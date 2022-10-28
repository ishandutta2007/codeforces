#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
struct data
{
	int w, x, idx;
};	
 
bool comp(data &d1, data &d2)
{
	if(d1.w != d2.w)
		return d1.w < d2.w;
	return d1.x > d2.x;
}
 
int n, m;
data a[N];
int join[N];
int ansu[N], ansv[N];
 
int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> a[i].w >> a[i].x;
		a[i].idx = i;
	}
	sort(a + 1, a + m + 1, comp);
	for(int i = 3; i <= n; i++)
		join[i] = i - 2;
	int u = 3, lim = 1, v = 1;
	for(int i = 1; i <= m; i++)
	{
		if(a[i].x == 1)
		{
			ansu[a[i].idx] = v;
			ansv[a[i].idx] = v + 1;
			v++;
		}
		else
		{
			if(join[u] == 0)
				u++;
			if(u > v)
			{
				cout << -1;
				return 0;
			}
			ansu[a[i].idx] = u;
			ansv[a[i].idx] = join[u];
			join[u]--;
		}
	}
	for(int i = 1; i <= m; i++)
		cout << ansu[i] << " " << ansv[i] << endl;
	return 0;
}