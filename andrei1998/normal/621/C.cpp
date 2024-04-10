#include <bits/stdc++.h>

using namespace std;

pair <int, int> v[100005];

double p(int l, int r, int pr) {
    return ((double)((r / pr) - ((l - 1) / pr))) / (r - l + 1);
}

double nextt(int l1, int r1, int l2, int r2, int pr) {
    return 1 - (1 - p(l1, r1, pr)) * (1 - p(l2, r2, pr));
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0, P;
    cin >> n >> P;

    for (int i = 1; i <= n; ++ i)
        cin >> v[i].first >> v[i].second;

    double ans = 0;
    for (int i = 1; i < n; ++ i)
        ans += nextt(v[i].first, v[i].second, v[i + 1].first, v[i + 1].second, P);
    ans += nextt(v[n].first, v[n].second, v[1].first, v[1].second, P);

    cout << fixed << setprecision(8) << 2000 * ans << '\n';
    return 0;
}