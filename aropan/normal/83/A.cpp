#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 111111;

int a[MAXN];
int n;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    long long ans = 0;
    for (int i = 0, j = 0; i < n; i = j)
    {
        while (j < n && a[i] == a[j]) j++;
        long long m = j - i;
        ans += m * (m + 1) / 2;
    }
    cout << ans << endl;
    return 0;
}