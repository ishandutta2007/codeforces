#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

const int NMAX = 100000 + 5;

int v[NMAX];
map <int, int> cnt;

int main()
{
    ios_base :: sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++ i) {
        cin >> v[i];
        ++ cnt[v[i]];
    }
    sort(v + 1, v + N + 1);

    lint ans = 0;
    if (v[1] != v[2]) {
        if (v[2] != v[3])
            ans = cnt[v[3]];
        else
            ans = cnt[v[2]] * (cnt[v[2]] - 1LL) / 2;
    }
    else {
        if (v[2] != v[3])
            ans = cnt[v[3]];
        else
            ans = cnt[v[1]] * (cnt[v[1]] - 1LL) * (cnt[v[1]] - 2LL) / 6;
    }

    cout << ans << '\n';
    return 0;
}