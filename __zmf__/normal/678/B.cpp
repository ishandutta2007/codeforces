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
const int N = 1e5 + 9;
int T, n, k;
int p;
inline int check(int x)
{
	if(x % 400 == 0) return 1;
	else if(x % 100 == 0) return 0;
	else if(x % 4 == 0) return 1;
	else return 0;
}
signed main()
{
	n = read(); int now = 0;
	if(check(n)) p = 1;
	for (int i = n + 1; i <= n + 1000; i++)
	{
		int p1 = check(i);
		if(p1) now += 2;
		else now += 1;
		if(p1 == p && now % 7 == 0)
		{
			cout << i << endl;
			return 0;
		}
	}
}
/*
4 4
1 2
1 3
2 4
3 4
*/