/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/

/*
	
*/

/*
	
*/

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
inline int read()
{
	int sum = 0, nega = 1;
	char ch = getchar();
	while (ch > '9'||ch < '0')
	{
	    if (ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 3e5 + 9, T = 89; 
vector<int> G[N];
int siz[N], vis[N], a[N], cnt, b[N], c[N];
int n, q;
ll rd[T + 9];
inline int getval(int l, int r, int v) 
{
	return upper_bound(G[v].begin(), G[v].end(), r) - lower_bound(G[v].begin(), G[v].end(), l); 
}
signed main()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	mt19937 rand_num(seed); 
	uniform_int_distribution<long long> dist(0, 1000000000000000000);
	n = read(), q = read();
	for (int i = 1; i <= T; i++) rd[i] = dist(rand_num);
	for (int i = 1; i <= n; i++) 
	{
		int x = read(); b[i] = x;
		G[x].push_back(i); siz[x]++;
	}
	for (int i = 1; i <= q; i++) 
	{
		int ans = 1e9, l = read(), r = read(), k = read();
		unsigned ll now;
		ll len = (r - l + 1);
		cnt = 0;
		for (int j = 1; j <= T; j++) 
		{
			now = rd[j];
			int pos = now % len; 
			if(vis[pos]) continue;
			a[++cnt] = b[pos + l]; 
			c[cnt] = pos;
			vis[pos] = 1;
			//cout << cnt << " " << now + l << " " << b[now + l] << " " << a[cnt] << endl;
		}
		for (int j = 1; j <= cnt; j++) 
		{
		//	cout << a[j] << endl;
			vis[c[j]] = 0;
			if(siz[a[j]] <= len / k) continue;
			int v = getval(l, r, a[j]); 
			if(v > len / k) ans = min(ans, a[j]);
		}
		if(ans != 1e9) printf("%d\n", ans);
		else puts("-1");
	}
	return 0;
}