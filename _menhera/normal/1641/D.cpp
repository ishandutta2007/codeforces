#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi2,popcnt")

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<pair<vector<int>, int>> A(N, {vector<int>(M), 0});

    vector<int> coord;
    for (auto &y : A)
    {
        auto &[a, b] = y;
        for (int &x : a)
            cin >> x, coord.push_back(x);
        cin >> b;
    }
    sort(coord.begin(), coord.end());
    coord.erase(unique(coord.begin(), coord.end()), coord.end());

    int base = coord.size() + 1;

    vector<__int128> V;
    for (auto &y : A)
    {
        auto &[a, b] = y;
        for (int &x : a)
            x = (lower_bound(coord.begin(), coord.end(), x) - coord.begin()) + 1;
        sort(a.begin(), a.end());
        for (int i = 1; i < (1 << M); i++)
        {
            __int128 cd = 0;
            for (int j = 0; j < M; ++j)
                if (i & (1 << j))
                    cd = cd * base + a[j];
            V.push_back(cd);
        }
    }

    sort(A.begin(), A.end(), [&](auto &a, auto &b)
         { return a.second < b.second; });

    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());

    vector<pair<vector<int>, int>> B(N, {vector<int>((1 << M) - 1), 0});
    for (int k = 0; k < N; k++)
    {
        B[k].second = A[k].second;
        for (int i = 1; i < (1 << M); i++)
        {
            __int128 cd = 0;
            for (int j = 0; j < M; ++j)
                if (i & (1 << j))
                    cd = cd * base + A[k].first[j];
            B[k].first[i - 1] = lower_bound(V.begin(), V.end(), cd) - V.begin();
        }
    }

    int tot = 0;
    vector<int> counter(V.size());
    auto add = [&](const vector<int> &n)
    {
        ++tot;
        for (int x : n)
            counter[x]++;
    };
    auto sub = [&](const vector<int> &n)
    {
        --tot;
        for (int x : n)
            counter[x]--;
    };
    auto check = [&](const vector<int> &n)
    {
        int ret = tot;
        for (int i = 1; i < (1 << M); i++)
            if (__builtin_popcount(i) & 1)
                ret -= counter[n[i - 1]];
            else
                ret += counter[n[i - 1]];
        return ret;
    };

    int L = 0, R = 0;
    while (R < N && !check(B[R].first))
        add(B[R++].first);
    if (R == N)
    {
        cout << -1 << endl;
        return 0;
    }
    L = R; //[0, L)
    int ans = INT_MAX;
    for (; R < N; ++R)
    {
        while (check(B[R].first))
            sub(B[--L].first);
        ans = min(ans, B[L].second + B[R].second);
    }

    cout << ans << endl;
}