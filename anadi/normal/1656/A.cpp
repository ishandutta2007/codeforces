#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);

    vector <int> vec(n + 1);
    int mn = 1, mx = 1;
    for (int i = 1; i <= n; ++i) {
        int v;
        scanf("%d", &v);
        vec[i] = v;

        if (v <= vec[mn]) {
            mn = i;
        }

        if (v >= vec[mx]) {
            mx = i;
        }
    }

    printf("%d %d\n", mx, mn);
}

int main()
{
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        solve();
    }

    return 0;
}