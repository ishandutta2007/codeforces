#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;

const ll   N     =  505;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, m, vis[N][N], sx, sy, ex, ey;
string s[N];
vector <int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

void dfs(int i, int j) {
	if (i == -1 || i == n) return;
	if (j == -1 || j == m) return;
	if (s[i][j] == 'X' || vis[i][j]) return;
	vis[i][j] = 1;
	for (int no = 0; no < 4; no++) {
		dfs(i + dx[no], j + dy[no]);
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	cin >> sx >> sy;
	cin >> ex >> ey;
	s[sx - 1][sy - 1] = '.';
	dfs(sx - 1, sy - 1);
	auto val = [&](int i, int j) -> int{
		if (i == -1 || i == n) return 0;
		if (j == -1 || j == m) return 0;
		return vis[i][j];
	};
	
	int ans = -vis[ex - 1][ey - 1];
	ans += (sx == ex && sy == ey);
	for (int no = 0; no < 4; no++) {
		ans += val(ex - 1 + dx[no], ey - 1 + dy[no]);
	}
	
	if (ans > 0) deb1("YES")
	else deb1("NO")
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}