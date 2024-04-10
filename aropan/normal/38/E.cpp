#include <cstdio>
#include <algorithm>
#include <iostream>

#define X first
#define C second

using namespace std;

const int MAXN = 3003;

long long f[MAXN];
int n;
pair <long long, long long> a[MAXN];

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x, c;
        scanf("%d %d", &x, &c);
        a[i].X = x;
        a[i].C = c;
    }
    sort(a, a + n);
    
    
    f[0] = a[0].C;
    a[n].X = a[n - 1].X;
    a[n].C = 0;
    for (int i = 1; i <= n; i++)
    {
        long long s = 0;
        f[i] = (long long)1e+20;
        for (int j = i - 1; j > 0; j--)
        {
            f[i] = min(f[i], f[j] + s);
            s += (a[j].X - a[j - 1].X) * (i - j);
        }
        f[i] = min(f[i], f[0] + s);
        f[i] += a[i].C;
    }
    cout << f[n] << endl;
    return 0;
}