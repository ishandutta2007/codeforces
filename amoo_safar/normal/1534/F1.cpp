// vaziat meshki-ghermeze !
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
const int N = 8e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

str A[N];
int n, m;
int tp[N], a[N], mk[N];
vector<int> G[N], H[N];

void Add(int i, int j){
	G[i].pb(j);
	H[j].pb(i);
}
int Get(int i, int j){ return i * m + j; }

pll dir[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool valid(int i, int j){
	return 0 <= min(i, j) && i < n && j < m;
}

vector<int> ord;
void DFS(int u){
	mk[u] = 1;
	for(auto adj : G[u])
		if(!mk[adj])
			DFS(adj);
	ord.pb(u);
}
int com[N];
void COL(int u, int cm){
	mk[u] = 1;
	com[u] = cm;
	for(auto adj : H[u])
		if(!mk[adj])
			COL(adj, cm);
}

int pas[N], pas2[N], rs[N], ls[N];

void COLP(int u, int cm){
	mk[u] = 1;
	com[u] = cm;
	for(auto adj : H[u])
		if(!mk[adj] && pas[adj])
			COLP(adj, cm);
}

int mxr[N];
void Add_seg(int l, int r){
	mxr[l] = max(mxr[l], r);
	// cerr << "** " << l << ' ' << r << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	iota(mxr, mxr + N, 0);

	cin >> n >> m;
	vector< vector<int> > fs(n, vector<int>(m, -1));

	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < m; i++)
		cin >> a[i];

	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j < m; j++){
			if(A[i][j] == '#')
				fs[i][j] = i * m + j;
			else
				fs[i][j] = (i == n - 1 ? -1 : fs[i + 1][j]);
		}
	}
	////
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int u = Get(i, j);
			if(A[i][j] == '.') continue;
			for(auto [dx, dy] : dir){
				int nx = i + dx;
				int ny = j + dy;
				if(!valid(nx, ny)) continue;
				if(fs[nx][ny] == -1) continue;
				Add(u, fs[nx][ny]);
			}
		}
	}
	/////
	// int ans = 0;
	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < m; j++){
	// 		if(A[i][j] == '.') continue;
	// 		if(mk[Get(i, j)]) continue;
	// 		DFS(Get(i, j));
	// 		// cerr << "$ " << i << ' ' << j << '\n';
	// 		ans ++;
	// 	}
	// }
	memset(mk, 0, sizeof mk);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(A[i][j] == '.') continue;
			int u = Get(i, j);
			if(mk[u]) continue;
			// cerr << "^^ " << u << '\n';
			DFS(u);
		}
	}
	memset(mk, 0, sizeof mk);
	reverse(all(ord));
	int col = 1;

	for(auto u : ord){
		if(!mk[u])
			COL(u, col ++);
	}
	
	for(int j = 0; j < m; j++){
		int rm = a[j];
		int bt = -1;
		for(int i = n - 1; i >= 0; i--){
			if(A[i][j] == '.') continue;
			rm --;
			if(rm == 0)
				bt = Get(i, j);
			if(rm <= 0)
				pas[Get(i, j)] = 1;
		}
		if(bt != -1){
			int gd = com[bt];
			for(int i = 0; i < n; i++)
				if(A[i][j] == '#' && com[Get(i, j)] == gd)
					pas[Get(i, j)] = 1;
		}
		// if(a[j] == 0){
		// 	for(int i = 0; i < n; i++)
		// 		if(A[i][j] == '#')
		// 			pas[Get(i, j)] = 1;
		// }
	}
	for(int i = 0; i < m*n; i++)
		pas2[i] = pas[i];
	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < m;j++) cerr << pas[Get(i, j)];
	// 	cerr << '\n';
	// }
	memset(mk, 0, sizeof mk);
	memset(com, 0, sizeof com);

	for(int j = m - 1; j >= 0; j--){
		int rm = a[j];

		// for(int i = 0; i < n; i++)
		// 	if(A[i][j] == '#')
		// 		pas[Get(i, j)] = 1;

		for(int i = n - 1; i >= 0; i--){
			// cerr<<"# " << Get(i, j) << '\n';
			if(A[i][j] == '.') continue;
			rm --;
			// if(rm <= 0){
			if(pas[Get(i, j)]){
				if(!mk[Get(i, j)])
					COLP(Get(i, j), j);
			}
		}
		// for(int i = n - 1; i >= 0; i--){
		// 	if(pas[Get(i, j)] == 1)
		// 		assert(mk[Get(i, j)] == 1);
		// }
	}
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
		rs[Get(i, j)] = com[Get(i, j)];
	

	for(int i = 0; i < m*n; i++)
		pas[i] = pas2[i];

	memset(mk, 0, sizeof mk);
	memset(com, 0, sizeof com);
	for(int j = 0; j < m; j++){
		int rm = a[j];

		for(int i = n - 1; i >= 0; i--){
			// cerr<<"# " << Get(i, j) << '\n';
			if(A[i][j] == '.') continue;
			rm --;
			if(pas[Get(i, j)]){
			// if(rm <= 0){
				if(!mk[Get(i, j)])
					COLP(Get(i, j), j);
			}
		}
	}
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
		ls[Get(i, j)] = com[Get(i, j)];
	
	for(int i = 0; i < n*m; i++)
		if(pas2[i])
			Add_seg(ls[i], rs[i]);
	
	for(int i = 1; i < m; i++){
		mxr[i] = max(mxr[i], mxr[i - 1]);
	}
	int po = -1;
	int ans = 0;
	for(int i = 0; i < m; i++){
		if(a[i] != 0 && po < i){
			ans ++;
			po = mxr[i];
		}
	}
	// cerr << "!! ";
	// for(int i = 0; i <= m + 1; i++) cerr << tp[i] << ' ';
	// cerr << '\n';

	// for(int i = 1; i <= m; i++){
	// 	if(tp[i] > 0 && tp[i - 1] < tp[i] && tp[i] >= tp[i + 1])
	// 		ans ++;
	// }
	cout << ans << '\n';
	
	return 0;
}
/*
4 5
##.##
#...#
#...#
##.#.
4 2 0 2 3

3 3
.#.
.#.
###
1 0 1

5 5
....#
.....
...##
....#
..###
0 0 1 2 4


5 5
#...#
.....
##.##
#...#
#####
4 2 1 2 4


*/