/*
	
	
	
	
	
	

	
	
	
										Naicissu
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
	while (ch <= '9'&&ch >= '0')sum=sum*10+ch-'0',ch=getchar();
	return sum * nega;
}
int T, W, H, w1, w2, h1, h2, w, h, answ, ansh, now;
int ans;
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++)
	{
		W = read(), H = read();
		w1 = read(), h1 = read(), w2 = read(), h2 = read(), w = read(), h = read(); 
		if(w + (w2 - w1) > W && h + (h2 - h1) > H)
		{
			puts("-1");
			continue;
		} 
		if(w + (w2 - w1) <= W)ans = min(max(0ll, w - w1), max(0ll, w2 - (W - w)));
		else ans = 1e18;
	//	cout << ans << endl;
		if(h + (h2 - h1) <= H)
		{
			ans = min(ans, max(0ll, h - h1));
			ans = min(ans, max(0ll, h2 - (H - h)));
		}
		cout << ans << endl; 
	}
	return 0;
}