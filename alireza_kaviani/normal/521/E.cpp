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
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , m , mark[MAXN] , H[MAXN] , par[MAXN] , cnt[MAXN];
pii val[MAXN];
vector<int> adj[MAXN] , backEdge[MAXN];

void DFS(int v){
	mark[v] = 1;
	for(int u : adj[v]){
		if(mark[u] == 1 && u != par[v]){
			backEdge[v].push_back(u);			
		}
		if(mark[u])	continue;
		H[u] = H[v] + 1;
		par[u] = v;
		DFS(u);
	}
	mark[v] = 2;
}

pii add(int v , int u){
	int x = 0 , y = 0;
	while(v != u){
		if(cnt[v] && x == 0){
			x = v;
		}
		cnt[v]++;
		v = par[v];
	}
	y = x;
	while(cnt[y] == 2){
		y = par[y];
	}
	return {x , y};
}

void Path(int v , int u , vector<int> &A , int rev){
	vector<int> vec;
	while(v != u){
		vec.push_back(v);
		v = par[v];
	}
	vec.push_back(u);
	if(rev){
		reverse(all(vec));
	}
	for(int i : vec){
		A.push_back(i);
	}
}

void Print(vector<int> A){
	cout << SZ(A) << sep;
	for(int i : A){
		cout << i << sep;
	}
	cout << endl;
}

void solve(int a , int b , int x , int y){
	cout << "YES" << endl;
	add(a , b); 
	pii insect = add(x , y);
	int v = insect.X , u = insect.Y;
	vector<int> A , B , C;
	Path(v , u , A , 0);
	Path(a , v , B , 1); Path(u , b , B , 1);
	Path(x , v , C , 1); Path(u , y , C , 1);
	Print(A); Print(B); Print(C);
	exit(0);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> m;
	for(int i = 0 ; i < m ; i++){
		int v , u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	for(int i = 1 ; i <= n ; i++){
		if(!mark[i]){
			DFS(i);
		}
	}

	for(int i = 1 ; i <= n ; i++){
		for(int j : backEdge[i]){
			int x = i;
			pii res = {0 , 0};
			while(x != j){
				res = max(res , val[x]);
				val[x] = {i , j};
				x = par[x];
			}
			if(res != pii(0 , 0)){
				solve(i , j , res.X , res.Y);
			}
		}
	}
	cout << "NO" << endl;

    return 0;
}
/*

*/