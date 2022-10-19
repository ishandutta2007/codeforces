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

const ll MAXN = 1e3 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int dx[4] = {1 , -1 , 0 , 0} , dy[4] = {0 , 0 , 1 , -1};
ll n , m , k , cnt , val , A[MAXN][MAXN] , mark[MAXN][MAXN] , par[MAXN * MAXN] , sz[MAXN * MAXN];
vector<pair<ll, pll>> vec;

int Find(int v){
	return (par[v] == -1 ? v : par[v] = Find(par[v]));
}

void Union(int v , int u){
	v = Find(v); u = Find(u);
	if(v == u)	return;
	if(sz[v] < sz[u])	swap(v , u);
	par[u] = v;
	sz[v] += sz[u];
}

void Print(){
	cout << "YES" << endl;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cout << mark[i][j] * val << sep;
		}
		cout << endl;
	}
	exit(0);
}

void DFS(int x , int y){
	mark[x][y] = 1;
	cnt--;
	if(cnt == 0){
		Print();
	}
	for(int i = 0 ; i < 4 ; i++){
		int nx = x + dx[i] , ny = y + dy[i];
		if(nx < 0 || ny < 0 || A[nx][ny] < val || mark[nx][ny])	continue;
		DFS(nx , ny);
	}
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	fill(par , par + MAXN * MAXN , -1);
	fill(sz , sz + MAXN * MAXN , 1);

	cin >> n >> m >> k;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> A[i][j];
			vec.push_back({A[i][j] , {i , j}});
		}
	}
	sort(all(vec) , greater<pair<ll, pll>>());
	for(pair<ll , pll> i : vec){
		val = i.X;
		int x = i.Y.X , y = i.Y.Y;
		mark[x][y] = 1;
		for(int j = 0 ; j < 4 ; j++){
			int nx = x + dx[j] , ny = y + dy[j];
			if(nx < 0 || ny < 0 || mark[nx][ny] == 0)	continue;
//			cout << x << sep << y << sep << nx << sep << ny << endl;
			Union(x * m + y , nx * m + ny);
		}
		if(k % val == 0 && sz[Find(x * m + y)] * val >= k){
			memset(mark , 0 , sizeof(mark));
			cnt = k / val;
			DFS(x , y);
		}
	}
	cout << "NO" << endl;

    return 0;
}
/*

*/