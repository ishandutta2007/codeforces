///
///   Oh? You're approaching me?
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 5010;
const int mod = 1e9+7;
int cnt[3][N];
vector<int> grass[N];
vector<int> el[N], er[N];
vector<int> ell[N], err[N];
int n, m;

int mx, fmx;
ll cntt = 1, fcnt = 0;

ll rev(ll x){ll y=mod-2,ans=1;while(y){if(y&1)ans=ans*x%mod;x=x*x%mod;y>>=1;}return ans;}

int getmx(int j)
{
	if (cnt[0][j] && cnt[1][j] && cnt[0][j]+cnt[1][j]-cnt[2][j] >= 2)
		return 2;
	if (cnt[0][j] || cnt[1][j])
		return 1;
	return 0;
}
ll getcnt(int mx, int j) {
	if (mx == 2)
		return (cnt[0][j] * cnt[1][j] - cnt[2][j]) % mod;
	if (mx == 1)
		return (cnt[0][j] + cnt[1][j]) % mod;
	return 1;
}

void add(int i, int j, int y)
{
	{
		int tmp = getmx(j);
		cntt = cntt*rev(getcnt(tmp, j)) % mod;
		mx -= tmp;
	}
	cnt[i][j] += y;
	{
		int tmp  = getmx(j);
		cntt = cntt*getcnt(tmp, j) % mod;
		mx += tmp;
	}
}
void up() {
//	cout << mx << ' ' << cntt << "!\n";
	if (mx > fmx) {
		fmx = mx;
		fcnt = 0;
	}
	if (mx == fmx)
		fcnt = (fcnt+cntt) % mod;
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m;
	Loop (i,0,n) {
		int x;
		cin >> x;
		grass[x-1].push_back(i);
	}
	Loop (i,0,m) {
		int x, y;
		cin >> x >> y;
		if (y > grass[x-1].size())
			continue;
		int a = grass[x-1][y-1];
		int b = grass[x-1][grass[x-1].size()-y];
		el[a].push_back(x-1);
		er[b].push_back(x-1);
		if (a < b) {
			ell[a].push_back(x-1);
			err[b].push_back(x-1);
		}
		add(1, x-1, 1);
	}
//	cout << cnt[0][0] << cnt[1][0] << cnt[2][0] << '\n';
//	cout << "-1" << ' ';
	up();
	Loop (i,0,n) {
		for (int x : er[i])
			add(1, x, -1);
		for (int x : err[i])
			add(2, x, -1);
		for (int x : ell[i])
			add(1, x, -1);
		for (int x : el[i]) {
			int y = cnt[0][x];
			int z = cnt[2][x];
			add(0, x, 1-y);
			add(2, x, -z);
//			cout << cnt[0][0] << cnt[1][0] << cnt[2][0] << '\n';
//			cout << i << ' ';
			up();
			add(2, x, z);
			add(0, x, y-1);
		}
		for (int x : el[i])
			add(0, x, 1);
		for (int x : ell[i]) {
			add(1, x, 1);
			add(2, x, 1);
		}
	}
	cout << fmx << ' ' << fcnt << '\n';
}