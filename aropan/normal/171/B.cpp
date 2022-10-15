#include <cstdio>
#include <algorithm>
#include <iostream>
#include <ctime>

using namespace std;


long long ans;
int n;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    scanf("%d", &n);
    ans = 1;
    for (int i = 2; i <= n; i++)
        ans += (i - 1) * 12;
    cout << ans << endl;

    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}