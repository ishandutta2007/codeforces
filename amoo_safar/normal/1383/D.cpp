// Null
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 260;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll A[N][N], mr[N], mc[N];
ll mk[N * N];
vector<pll> Fr;

map<int, int> R, C;
set<int> st;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	ll v;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> v;
			mr[i] = max(mr[i], v);
			mc[j] = max(mc[j], v);
		}
	}
	for(int i = 0; i < n; i++){
		st.insert(mr[i]);
		R[mr[i]] = 1;
	}
	for(int i = 0; i < m; i++){
		st.insert(mc[i]);
		C[mc[i]] = 1;
	}
	vector<ll> V;

	for(auto x : st){
		V.pb(x);
		mk[x] = 1;
	}
	reverse(all(V));
	A[0][0] = n * m;
	
	
	int rn = 0, cn = 0;
	for(int i = 1; i < (int) V.size(); i++){
		v = V[i];
		if(R[v]){
			for(int j = (C[v] ? cn : cn - 1); j >= 0; j--) Fr.pb({rn + 1, j});
		}
		if(C[v]){
			for(int j = (R[v] ? rn : rn - 1); j >= 0; j--) Fr.pb({j, cn + 1});			
		}
		if(R[v]) rn ++;
		if(C[v]) cn ++;
		A[rn][cn] = v;
	}
	for(int i = 1; i <= n*m; i++){
		if(mk[i]) continue;
		A[Fr.back().F][Fr.back().S] = i;
		Fr.pop_back();
	}


	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) cout << A[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}