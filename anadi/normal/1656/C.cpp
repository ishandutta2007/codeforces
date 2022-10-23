#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);

    vector <int> vec(n);
    for (int &v: vec) {
        scanf("%d", &v);
    }

    bool is_one = false;
    for (int v: vec) {
        is_one |= v == 1;
    }

    if (!is_one) {
        puts("YES");
        return;
    }

    sort(vec.begin(), vec.end());
    for (int i = 1; i < n; ++i) {
        if (vec[i] == vec[i - 1] + 1) {
            puts("NO");
            return;
        }
    }

    puts("YES");
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