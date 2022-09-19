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
const int N = 1e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll n, m, t;
int a[N][N];
int mk[N][N];
int st[N][N];

pll adj[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool val(ll i, ll j){
	return (0 <= i) && (i < n) && (0 <= j) && (j < m);
}

int com = 1, cnt = 0;
void DFS(int i, int j){
	mk[i][j] = com;
	cnt ++;
	int nx, ny;
	for(auto del : adj){
		nx = del.F + i;
		ny = del.S + j;
		if(!val(nx, ny)) continue;
		if(mk[nx][ny]) continue;
		if(a[i][j] != a[nx][ny]) continue;
		DFS(nx, ny);
	}
}

ll dis[N][N];
deque<pair<int, int>> dq;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> t;
	str s;
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < m; j++) a[i][j] = s[j]-'0';
	}
	memset(dis, 31, sizeof dis);

	int nx, ny, fl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			fl = 0;
			for(auto del : adj){
				nx = del.F + i;
				ny = del.S + j;
				//cerr << nx << ' ' << ny << '\n';
				if(!val(nx, ny)) continue;
				//cerr << "KIT\n";
				//cerr << a[i][j] << a[nx][ny] << '\n';
				if(a[i][j] != a[nx][ny]) continue;
				fl = 1;
			}
			if(fl){
				//cerr << i << ' ' << j << '\n';
				dis[i][j] = 0;
				dq.push_back({i, j});
			}
		}
	}
	int i, j, w;
	while(dq.size() > 0){
		i = dq.front().F;
		j = dq.front().S;
		dq.pop_front();
		for(auto del : adj){
			nx = del.F + i;
			ny = del.S + j;
			if(!val(nx, ny)) continue;
			if(a[i][j] != a[nx][ny]) w = 1;
			else w = 0;

			if(dis[nx][ny] > dis[i][j] + w){
				dis[nx][ny] = dis[i][j] + w;
				if(w) dq.pb({nx, ny});
				else dq.push_front({nx, ny});
			}
		}
	}
	ll x, y, p;
	for(int i = 0; i < t; i++){
		cin >> x >> y >> p;
		x--; y--;
		//debug(dis[x][y]);
		if(dis[x][y] > N*N) cout << a[x][y] << '\n';
		else {
			if(p <= dis[x][y]) cout << a[x][y] << '\n';
			else {
				if(p % 2 != dis[x][y] % 2) cout << 1 - a[x][y] << '\n';
				else cout << a[x][y] << '\n';
			}
		}
	}
	return 0;
}