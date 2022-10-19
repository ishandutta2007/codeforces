#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll SIG = 26;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , timer , trieInd , A[MAXN] , pos[MAXN] , st[MAXN] , fn[MAXN] , fen[MAXN] , F[MAXN] , nxt[MAXN][SIG];
vector<int> adj[MAXN];

int insert(string s){
	int cur = 0;
	for(int i = 0 ; i < SZ(s) ; i++){
		int ch = s[i] - 97;
		if(nxt[cur][ch] == 0){
			nxt[cur][ch] = ++trieInd;
		}
		cur = nxt[cur][ch];
	}
	return cur;
}

void buildAho(){
	queue<int> Q;
	Q.push(0);
	while(!Q.empty()){
		int v = Q.front(); Q.pop();
		if(v != 0){
			//cout << v << sep << F[v] << endl;
			adj[F[v]].push_back(v);
		}
		for(int i = 0 ; i < 26 ; i++){
			if(nxt[v][i] == 0){
				nxt[v][i] = nxt[F[v]][i];
			}
			else{
				F[nxt[v][i]] = (v == 0 ? 0 : nxt[F[v]][i]);
				Q.push(nxt[v][i]);
			}
		}
	}
}

void DFS(int v){
	st[v] = timer++;
	for(int u : adj[v]){
		DFS(u);
	}
	fn[v] = timer;
}

void add(int x , int v){
	for(x += 5 ; x < MAXN ; x += x & -x)	fen[x] += v;
}

int get(int x){
	int ans = 0;
	for(x += 5 ; x ; x -= x & -x)	ans += fen[x];
	return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q >> n;
	for(int i = 1 ; i <= n ; i++){
		string s;
		cin >> s;
		pos[i] = insert(s);
	}
	buildAho();
	DFS(0);
	for(int i = 1 ; i <= n ; i++){
		//cout << st[pos[i]] << sep << fn[pos[i]] << endl;
		A[i] = 1;
		add(st[pos[i]] , 1);
		add(fn[pos[i]] , -1);
	}
	while(q--){
		char c;
		cin >> c;
		if(c == '?'){
			string s;
			cin >> s;
			ll cur = 0 , ans = 0;
			for(int i = 0 ; i < SZ(s) ; i++){
				int ch = s[i] - 97;
				cur = nxt[cur][ch];
				ans += get(st[cur]);
			}
			cout << ans << endl;
		}
		else{
			int ind;
			cin >> ind;
			int cost = (c == '+' ? 1 : -1);
			if(A[ind] == cost)	continue;
			add(st[pos[ind]] , cost);
			add(fn[pos[ind]] , -cost);
			A[ind] = cost;
		}
	}

    return 0;
}
/*

*/