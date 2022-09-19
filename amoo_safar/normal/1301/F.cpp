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
const int N = 1e6 + 4000;
const int M = 1e3 + 10;
const int K = 42;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int Z = 1002;

vector<int> oc[K];
int mk[K];
pair<int, int> adj[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int dis[K][N], a[M][M];

queue<int> q;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
			oc[a[i][j]].pb({Z*i + j});
		}
	}
	memset(dis, 31, sizeof dis);
	int fr, nx, ny, x, y;
	for(int i = 1; i <= k; i++){
		memset(mk, 0, sizeof mk);
		for(auto nd : oc[i]){
			dis[i][nd] = 0;
			q.push(nd);
		}
		while(q.size()){
			fr = q.front(); q.pop();
			y = fr % Z;
			x = fr / Z;
			//cerr << x << " " << y << " " << dis[i][fr] << '\n';
			if(!mk[a[x][y]]){
				for(auto nd : oc[a[x][y]]){
					if(dis[i][nd] > dis[i][fr] + 1){
						dis[i][nd] = dis[i][fr] + 1;
						q.push(nd);
					}
				}
				mk[a[x][y]] = 1;
			}
			for(auto del : adj){
				nx = x + del.F;
				ny = y + del.S;
				if((nx < 1) || (nx > n) || (ny < 1) || (ny > m)) continue;
				//debug(nx); debug(ny);
				if(dis[i][Z*nx + ny] > dis[i][fr] + 1){
					dis[i][Z*nx + ny] = dis[i][fr] + 1;
					q.push(Z*nx + ny);
				}
			}
		}
	}
	int q;
	cin >> q;
	int ans, x1, x2, y1, y2;
	for(int i = 0; i < q; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		ans = abs(x1 - x2) + abs(y1 - y2);
		for(int j = 1; j <= k; j++) ans = min(ans, 1 + dis[j][Z*x1 + y1] + dis[j][Z*x2 + y2]);
		//debug(dis[1][Z*x2 + y2]);
		cout << ans << '\n';
	}
	
	return 0;
}