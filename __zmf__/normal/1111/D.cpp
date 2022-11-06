/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define int long long
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
const int N = 1e5 + 9, mod = 1e9 + 7;
int n, m, a[N], jc[N], inv[N], v, ans[59][59], q, dp1[59][N], dp2[59][N], sum[N];
bool vis[N]; 
char s[N];
inline int Pow(int x, int y)
{
	int res = 1, base = x;
	while(y)
	{
		if(y & 1) res = res * base % mod;
		base = base * base % mod;
		y >>= 1;
	}
	return res;
}
inline void init()
{
	jc[0] = 1;
	for (int i = 1; i <= n; i++) jc[i] = jc[i - 1] * i % mod;
	inv[n] = Pow(jc[n], mod - 2);
	for (int i = n - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
	return ;
}
int P;
signed main()
{
  	m = 52;
  	scanf("%s", s + 1);
	n = strlen(s + 1);
  	init();
  	v = jc[n / 2] * jc[n / 2] % mod;
  	for (int i = 1; i <= n; i++)
  	{
	  	if(s[i] >= 'A' && s[i] <= 'Z') a[s[i] - 'A' + 1]++;
	  	else a[s[i] - 'a' + 27]++;
	}
//	for (int i = 1; i <= m; i++) cout << a[i] << endl;
  	for (int i = 1; i <= m; i++) v = v * inv[a[i]] % mod;
  	for (int i = 1; i <= m; i++)
  		if(a[i] != 0)
		{
	  		vis[i] = 1;
	  		//memset(dp1, 0, sizeof(dp1)); memset(dp2, 0, sizeof(dp2));
			for (int j = 0; j <= m + 1; j++)	 
	  			for (int k = 0; k <= n / 2; k++) dp1[j][k] = dp2[j][k] = 0;
	  		dp1[0][0] = dp2[m + 1][0] = 1;
	  		for (int j = 1; j <= m; j++)
	  			for (int k = n / 2; k >= 0; k--)
	  			{
	  				if(!vis[j]) dp1[j][k] = dp1[j - 1][k];
	  				if(a[j] != 0 && k >= a[j]) dp1[j][k] = (dp1[j][k] + dp1[j - 1][k - a[j]]) % mod;
				}
		//	cout << i << " " << clock() << endl; 
			for (int j = m; j >= 1; j--)
	  			for (int k = n / 2; k >= 0; k--)
	  			{
	  				if(!vis[j]) dp2[j][k] = dp2[j + 1][k];
	  				if(a[j] != 0 && k >= a[j]) dp2[j][k] = (dp2[j][k] + dp2[j + 1][k - a[j]]) % mod;
				}
		//	cout << i << " " << clock() << endl;
			for (int j = 1; j <= m; j++)
			{
				if(a[j] == 0) continue;
				int pp = n / 2 - a[j], res = 0;
				for (int k = 0; k <= pp; k++) res = (res + dp1[j - 1][k] * dp2[j + 1][pp - k] % mod) % mod;
				ans[i][j] = res;	
			}
		//	cout << i << " " << clock() << endl; 
			vis[i] = 0;
	}	
//	cout << v << endl;
  	q = read();
  	for (int ttt = 1; ttt <= q; ttt++)
  	{
  		int x = read(), y = read();
  		int idx = 0, idy = 0;
  		if(s[x] >= 'A' && s[x] <= 'Z') idx = s[x] - 'A' + 1;
  		else idx = s[x] - 'a' + 27;
  		if(s[y] >= 'A' && s[y] <= 'Z') idy = s[y] - 'A' + 1;
  		else idy = s[y] - 'a' + 27;
  		//cout << idx << " " << idy << endl;
  		printf("%lld\n", ans[idx][idy] * 2 % mod * v % mod);
	}
	return 0;
}
/*
ZbntHFIFBuavtylcuptFMJoBSlYGUnadhTPNHmnUqExWUSBEEBuuGxQiVLrrODmOSadswOPagtdQNadHoQofapdRigvOtLrmQVDXelInAaSBeRvFACbn
1
18 67
*/