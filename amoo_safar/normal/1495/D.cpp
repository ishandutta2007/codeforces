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

const ll Mod = 998244353;
const int N = 400 + 10;
const int M = 600 + 10;

const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int n, m;
int a[M], b[M];
int dis[N][N];

int d[N], p[N], cnt[N], c2[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	memset(dis, 31, sizeof dis);
	for(int i = 1; i <= n; i++) dis[i][i] = 0;
	for(int i = 1; i <= m; i++){
		cin >> a[i] >> b[i];
		dis[a[i]][b[i]] = 1;
		dis[b[i]][a[i]] = 1;
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int ds = dis[i][j];
			for(int k = 0; k <= ds; k++) c2[k] = 0;
			ll ans = 1;
			for(int k = 1; k <= n; k++){
				cnt[k] = 0;
				p[k] = (dis[i][k] + dis[j][k] - ds);
				if(p[k] % 2 == 1){
					ans = 0; 
					// cerr << "!$$ " << i << ' ' << j << ' ' << k << '\n'; 
					break;
				}
				p[k] /= 2;
				d[k] = dis[i][k] - p[k];
				if(d[k] < 0 || d[k] > ds) ans = 0;
				if(p[k] == 0) c2[d[k]] ++;
			}
			for(int k = 0; k <= ds; k++) if(c2[k] != 1) ans = 0;
			if(ans <= 0) {
				cout << "0" << " \n"[j == n]; 
				continue;
			}
			for(int e = 1; e <= m; e++){
				if(d[a[e]] != d[b[e]]) continue;
				if(p[a[e]] == p[b[e]] + 1) cnt[a[e]] ++;
				if(p[b[e]] == p[a[e]] + 1) cnt[b[e]] ++;
			}

			for(int k = 1; k <= n; k++) if(p[k] != 0)
				ans = (1ll * ans * cnt[k]) % Mod;

			cout << ans << " \n"[j == n];
		}
	}
	return 0;
}