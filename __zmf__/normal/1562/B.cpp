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
const int N = 59;
int T;
int n, ans, flag;
char s[N]; 
int a[N];
inline bool Isprime(int x)
{
	if(x == 1) return 0;
	for (int i = 2; i * i <= x; i++)
		if(x % i == 0) return 0;
	return 1;	
}
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++)
	{
		n = read();
		flag = 0;
		scanf("%s", s + 1);
		for (int i = 1; i <= n; i++) a[i] = s[i] - '0';
		//for (int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
		for (int i = 1; i <= n; i++)
			if(!Isprime(a[i]))
			{
				cout << "1\n" << a[i] << endl;
				flag = 1;
				break;
			}
		if(flag) continue;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
				if(!Isprime(a[i] * 10 + a[j]))
				{
					cout << "2\n" << a[i] << a[j] << endl;
					flag = 1;
					break;
				}
			if(flag) break;
		}
		if(flag) continue;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				for (int k = j + 1; k <= n; k++)	
					if(!Isprime(a[i] * 100 + a[j] * 10 + a[k]))
					{
						cout << "3\n" << a[i] << a[j] << a[k] << endl;
						flag = 1;
						break;
					}
				if(flag) break;
			}
			if(flag) break;
		}
	}
	return 0;
}