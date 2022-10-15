#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>


#define sqr(x) ((long long)(x) * (long long)(x))
             
using namespace std;

const int MAXN = 100005;

int n;
long long x, y;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    cin >> n >> x >> y;

    if (n > y || sqr(y - (n - 1)) + n - 1 < x)
    {
    	puts("-1");
    	return 0;
    }

    for (int i = 1; i < n; i++)
    	cout << 1 << endl;
    cout << y - (n - 1) << endl;
    
    return 0;
}