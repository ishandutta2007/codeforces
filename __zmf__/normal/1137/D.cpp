
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
	while (ch > '9' || ch < '0')
	{
	    if (ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 1009;
int n;
char s[N];
signed main()
{
	while(1)
	{
		cout << "next 0\n";
		fflush(stdout);
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> s;
		cout << "next 0 1\n";
		fflush(stdout);
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> s;
		if(n == 2) break;
	}
	while(1)
	{
		cout << "next 0 1 2 3 4 5 6 7 8 9\n";
		fflush(stdout);
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> s;
		if(n == 1) break;
	}
	cout << "done" << endl;
	return 0;
}