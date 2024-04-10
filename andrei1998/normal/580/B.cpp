#include <bits/stdc++.h>

#define lint long long int
using namespace std;

struct guy {
    int money;
    int fr;
} v[100005];

bool operator< (const guy &a, const guy &b) {
    return a.money < b.money;
}

int main () {
    ios_base :: sync_with_stdio(false);

    int n, d;
    cin >> n >> d;

    for (int i = 1; i <= n; ++ i)
        cin >> v[i].money >> v[i].fr;
    sort(v + 1, v + n + 1);

    if (d == 0) {
        lint best = 0;

        for (int i = 1; i <= n; ++i)
            if (v[i].fr > best)
                best = v[i].fr;

        return 0;
    }

    lint best = 0;
    lint sum = 0;

    int j = 0;
    for (int i = 1; i <= n; ++ i) {
        while (j + 1 <= n && v[j + 1].money - v[i].money < d) {
            ++ j;
            sum += v[j].fr;
        }

        if (sum > best)
            best = sum;

        sum -= v[i].fr;
    }

    cout << best << '\n';
    return 0;
}