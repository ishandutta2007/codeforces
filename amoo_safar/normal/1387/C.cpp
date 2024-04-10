// Null
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'
#define U S.F.F
#define V S.F.S
#define Ba S.S

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int G, n, m;
vector< pair<int, vector<int> > > con;
vector<int> req[N];

int b[N];

int nx[N][2], Sz = 1;
int F[N], bad[N], Que[N];

void Build(){
	int nw, l = 0, r = 0;
	for(int i = 0; i < 2; i++)
		if(nx[0][i])
			Que[r ++] = nx[0][i];
	while(r - l){
		nw = Que[l ++];
		bad[nw] |= bad[F[nw]];
		for(int i = 0; i < 2; i++)
			if(nx[nw][i])
				F[nx[nw][i]] = nx[F[nw]][i], Que[r ++] = nx[nw][i];
			else
				nx[nw][i] = nx[F[nw]][i];
	}
}


const int L = 52;
const int MV = 102;

ll dp[L][L][MV];


typedef pair<ll, pair< pair<int, int>, int> > T; 

set<T> st;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> G >> n >> m;
	int firstG = G;

	ll a, k;
	vector<int> R;
	for(int i = 1; i <= n; i++){
		cin >> a >> k;
		R.clear();
		for(int j = 0; j < k; j++) cin >> b[j];
		if(k == 1){
			R.pb(b[0]);
			con.pb({a, R});
			continue;
		}
		while(k > 2){
			R.clear();
			R.pb(b[k - 2]);
			R.pb(b[k - 1]);
			b[k - 2] = G;
			k --;
			con.pb({G, R});
			G ++;
		}
		R.clear();
		R.pb(b[0]);
		R.pb(b[1]);
		con.pb({a, R});
	}
	for(int i = 0; i < (int) con.size(); i++){
		for(auto y : con[i].S)
			req[y].pb(i);
	}
	
	assert(G <= MV);

	int ch;
	for(int i = 0; i < m; i++){
		cin >> k;
		int nw = 0;
		for(int i = 0; i < k; i++){
			cin >> ch;
			if(!nx[nw][ch]){
				nx[nw][ch] = Sz ++;
			}
			nw = nx[nw][ch];
		}
		bad[nw] = 1;
	}
	Build();
	{
		/*
		debug(Sz);
		for(auto x : con){
			
			cerr << '\n';
			cerr << x.F << " -> ";
			for(auto y : x.S) cerr << y << ' ';
			cerr << '\n';
			
		}
		for(int i = 0; i < Sz; i++) cerr << F[i] << ' ';
		cerr << '\n';
		cerr << '\n';
		*/
	}

	memset(dp, 31, sizeof dp);
	for(int i = 0; i < Sz; i++){
		//if(bad[i]) debug(i);
		if(bad[i]) continue;
		if(! bad[nx[i][0]]) dp[i][nx[i][0]][0] = 1;

		if(! bad[nx[i][1]]) dp[i][nx[i][1]][1] = 1;
		
		st.insert({dp[i][nx[i][0]][0], {{i, nx[i][0]}, 0}});
		st.insert({dp[i][nx[i][1]][1], {{i, nx[i][1]}, 1}});
	}

	//debug(Inf);
	//debug(dp[3][3][3]);

	T fr;
	while(!st.empty()){
		fr = *st.begin(); st.erase(st.begin());
		if(fr.F >= Inf) break;

		for(int tr : req[fr.Ba]){
			if(con[tr].S.size() == 1){
				if(dp[fr.U][fr.V][con[tr].F] > fr.F){
					st.erase({dp[fr.U][fr.V][con[tr].F], {fr.S.F, con[tr].F}});
					dp[fr.U][fr.V][con[tr].F] = fr.F;
					st.insert({dp[fr.U][fr.V][con[tr].F], {fr.S.F, con[tr].F}});
				}
				continue;
			}
			assert(con[tr].S.size() == 2);
			if(con[tr].S[0] == fr.Ba){
				for(int z = 0; z < Sz; z++){
					if(dp[fr.U][z][con[tr].F] > fr.F + dp[fr.V][z][con[tr].S[1]]){
						st.erase({dp[fr.U][z][con[tr].F], {{fr.U, z}, con[tr].F}});
						dp[fr.U][z][con[tr].F] = fr.F + dp[fr.V][z][con[tr].S[1]];
						st.insert({dp[fr.U][z][con[tr].F], {{fr.U, z}, con[tr].F}});
					}
				}
			}
			if(con[tr].S[1] == fr.Ba){
				for(int z = 0; z < Sz; z++){
					if(dp[z][fr.V][con[tr].F] > fr.F + dp[z][fr.U][con[tr].S[0]]){

						st.erase({dp[z][fr.V][con[tr].F], {{z, fr.V}, con[tr].F}});
						dp[z][fr.V][con[tr].F] = fr.F + dp[z][fr.U][con[tr].S[0]];
						st.insert({dp[z][fr.V][con[tr].F], {{z, fr.V}, con[tr].F}});
					}
				}
			}
		}
	}


	for(int i = 2; i < firstG; i++){
		ll answ = Inf;

		for(int j = 0; j < Sz; j++) answ = min(answ, dp[0][j][i]);

		if(answ >= Inf) cout << "YES\n";
		else cout << "NO " << answ << '\n';
	}
	return 0;
}