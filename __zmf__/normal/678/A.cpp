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
signed main()
{
	T = 1;
	for (int ttt = 1; ttt <= T; ttt++)
	{
		n = read(); k = read();
		cout << (n + k) / k * k << endl;
	}
    return 0;
}
/*
4 4
1 2
1 3
2 4
3 4
*/