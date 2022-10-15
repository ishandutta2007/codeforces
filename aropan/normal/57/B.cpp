#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 100001;
const int MAXK = 101;

int n, m;
int a[MAXN], b[MAXN], c[MAXN];


int main()
{
/*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
//*/
    scanf("%d %d %d", &n, &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
        
    long long ans = 0;
    for (int i = 0; i < m; i++)
    {
        int x;
        scanf("%d", &x);
        for (int j = 0; j < n; j++)
            if (a[j] <= x && x <= b[j])
                ans += x - a[j] + c[j];
    }
    cout << ans;
    return 0;
}