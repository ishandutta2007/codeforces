#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    scanf("%d %d", &n, &k);

    set <int> S;
    bool answer = false;

    for (int i = 1; i <= n; ++i) {
        int v;
        scanf("%d", &v);

        if (S.count(v + k) || S.count(v - k)) {
            answer = true;
        }

        S.insert(v);
    }

    puts(answer ? "YES" : "NO");
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