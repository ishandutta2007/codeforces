#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <cstdlib>
#include <time.h>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define y0 asdfasdf
#define y1 fdsafdsa

map < int , int > m;
const int maxn = 5003;
ll f[5][maxn*2];
int ql[maxn], qr[maxn];


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);
	
	int n, X;
	cin >> n >> X;
	vector < int > v;
	v.pb(X);
	for (int i = 1; i <= n; i++)
	{
		int l, r;
		cin >> l >> r;
		ql[i] = l, qr[i] = r;
		v.pb(l);
		v.pb(r);
	}
	sort(v.begin(), v.end());
	vector < int > vv;
	for (int i = 0; i < (int)v.size(); i++)
		if (i == 0 || v[i] != v[i-1])
		{
			m[v[i]] = (int)vv.size();
			vv.pb(v[i]);
		}
	for (int i = 0; i < (int)vv.size(); i++)
		f[0][i] = abs(X - vv[i]), f[3][i] = abs(X - vv[i]);
	ll INF = 1000000000 * 1ll * 1000000000;
	for (int i = 1; i <= n; i++)
	{
		int l = m[ql[i]], r = m[qr[i]];
		for (int j = 0; j < (int)vv.size(); j++)
			f[1][j] = INF, f[2][j] = INF;
		ll mini = INF;
		for (int j = 0; j <= l; j++)
		{
			mini = min(mini, vv[l] - vv[j] + f[0][j]);
			f[1][j] = mini;
		}
		for (int j = l + 1; j <= r; j++)
		{
			mini = min(mini + vv[j] - vv[j-1], f[0][j]);
			f[1][j] = mini;
		}
		for (int j = r + 1; j < (int)vv.size(); j++)
		{
			mini = min(mini + 2 * (vv[j] - vv[j-1]), f[0][j] + vv[j] - vv[r]);
			f[1][j] = mini;
		}
		
		
		mini = INF;
		
		
		for (int j = (int)vv.size() - 1; j >= r; j--)
		{
			mini = min(mini, vv[j] - vv[r] + f[0][j]);
			f[2][j] = mini;
		}
		for (int j = r - 1; j >= l; j--)
		{
			mini = min(mini + vv[j+1] - vv[j], f[0][j]);
			f[2][j] = mini;
		}
		for (int j = l - 1; j >= 0; j--)
		{
			mini = min(mini + 2 * (vv[j+1] - vv[j]), f[0][j] + vv[l] - vv[j]);
			f[2][j] = mini;
		}
		
		
		for (int j = 0; j < (int)vv.size(); j++)
			f[0][j] = min(f[1][j], f[2][j]);
			
		/*for (int j = 0; j < (int)vv.size(); j++)
		{
			f[4][j] = INF;
			for (int k = 0; k < (int)vv.size(); k++)
			{
				ll cur = f[3][k] + abs(vv[j] - vv[k]);
				if (j > r)
					cur += vv[j] - v
				f[4][j] = min(f[4][j], f[3][k] + abs(vv[j] - vv[k])
			}
		}*/
	}
	ll ans = INF;
	for (int i = 0; i < (int)vv.size(); i++)
		ans = min(ans, f[0][i]);
	cout << ans << "\n";
	
	//cerr << clock() * 1. / CLOCKS_PER_SEC << "\n";//  - curtime << "\n";
	return 0;
}