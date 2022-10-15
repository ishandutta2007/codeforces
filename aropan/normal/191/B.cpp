#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;


const int MAXN = 100005;

int n, k;
long long b;
long long a[MAXN], f[MAXN];
int s[MAXN], p[MAXN];

bool opr_sort(const int &i, const int &j)
{
	return a[i] > a[j];
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif

    cin >> n >> k;
    cin >> b;
    for (int i = 0; i < n; i++)
    {
    	cin >> a[i];
    	s[i] = i;
    }	
    n--;

    sort(s, s + n, opr_sort);
    for (int i = 0; i < n; i++)
    	p[s[i]] = i;

    for (int i = 1; i <= n; i++)
    	f[i] = f[i - 1] + a[s[i - 1]];

    for (int i = 0; i < n; i++)
    {
    	long long x = f[k - 1];
    	if (p[i] < k - 1)
    		x += a[s[k - 1]];
    	else
    		x += a[i];
    	if (x > b)
    	{
    		cout << i + 1 << endl;
    		return 0;
    	}
    }
    cout << n + 1 << endl;
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}