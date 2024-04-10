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
	while (ch <= '9'&&ch >= '0') sum = sum * 10 + ch - '0', ch = getchar ();
	return sum * nega;
}
inline int ask(int i, int j)
{
	cout << "SCAN " << i << " " << j << endl;
	int res;
	cin >> res; 
	return res;
}
inline int que(int i, int j) 
{
	cout << "DIG " << i << " " << j << endl;
	int res; 
	cin >> res;
	return res;
}
int n, m, sumx, sumy;
int fx, sx, fy, sy, pep;
inline void solve()
{
	n = read(), m = read();
	int f1 = ask(1, 1), f2 = ask(1, m);
	sumx = ((f1 + f2) - 2 * (m - 1)) / 2 + 2;
	sumy = f1 + 4 - sumx;
//	cout << sumx << " " << sumy << endl;
	pep = ask(sumx / 2, 1) - (sumy - 2); 
	fx = (pep + sumx) / 2, sx = (sumx - pep) / 2;
	pep = ask(1, sumy / 2) - (sumx - 2);
	fy = (pep + sumy) / 2, sy = (sumy - pep) / 2;
	if(fx == sx || fy == sy)
	{
		pep = que(fx, fy); pep = que(sx, sy); return ;
	}
	pep = que(fx, fy);
	if(pep) 
	{
		pep = que(sx, sy); return ;
	}
	else
	{
		pep = que(fx, sy); pep = que(sx, fy); return ;
	}
	return ;
}
signed main()
{
	int T;
	T = read();
	for (int ttt = 1; ttt <= T; ttt++) solve();
	return 0;
}