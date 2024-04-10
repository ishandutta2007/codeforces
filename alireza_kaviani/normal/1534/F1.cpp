#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , m , ans , cur , mark[MAXN];
string s[MAXN];
vector<int> vec , pos[MAXN] , id[MAXN] , adj[MAXN] , radj[MAXN];

void DFS(int v){
	mark[v] = 1;
	for(int u : adj[v]){
		if(!mark[u])	DFS(u);
	}
	vec.push_back(v);
}

void DFS2(int v){
	mark[v] = 1;
	for(int u : adj[v]){
		if(!mark[u])	DFS2(u);
	}
}

void SCC(){
	for(int i = 0 ; i < cur ; i++){
		if(!mark[i])	DFS(i);
	}
	reverse(all(vec));
	fill(mark , mark + MAXN , 0);
	for(int i : vec){
		if(!mark[i]){
			DFS2(i); ans++;
		}
	}
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> m;
	for(int i = 0 ; i < n ; i++){
		cin >> s[i]; s[i] = "." + s[i];
		for(int j = 1 ; j <= m ; j++){
			if(s[i][j] == '#'){
				pos[j].push_back(i);
//				cout << cur << sep << i << sep << j << endl;
				id[j].push_back(cur++);
			}
		}
	}
	for(int i = 1 ; i <= m ; i++){
		for(int j = 0 ; j < SZ(pos[i]) ; j++){
			for(int k = i - 1 ; k <= i + 1 ; k++){
				int ind = lower_bound(all(pos[k]) , pos[i][j]) - pos[k].begin();
				if(k == i)	ind++;
				if(ind == SZ(pos[k]))	continue;
				int v = id[i][j] , u = id[k][ind];
//				cout << v << sep << u << endl;
				adj[v].push_back(u);
				if(k == i && pos[i][j] + 1 == pos[i][j + 1])	adj[u].push_back(v);
			}
		}
	}
	SCC();
	cout << ans << endl;

    return 0;
}
/*

*/