#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 5e5 + 5;
int a[maxn];
vector < int > in[maxn];

void get(int k) {
    int ans = 0;
    for (int i = 1; i <= k; ++i) {
        sort(in[i].begin(), in[i].end());
        for (int j = 0; j < (int)in[i].size(); ++j) ans += j * in[i][j];
    }
    cout << ans;
    exit(0);
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    vector < int > ok;
    k++;
    int R = -1;
    for (int i = n; i >= 1; --i) {
        if (a[i] < 0) {
            for (int j = i + 1; j <= n; ++j) ok.push_back(a[j]);
            R = i;
            break;
        }
    }
    if (R == -1) {
        for (int i = 1; i <= n; ++i) in[1].push_back(a[i]);
        get(k);
    }
    vector < int > d;
    for (int i = 1; i <= R; ++i) {
        if (i % k == 0) in[1].push_back(a[i]);
        else {
            d.push_back(i);
            in[i % k + 1].push_back(a[i]);
        }
    }
    int ans = 0, cur = 0;
    for (auto key : ok) in[1].push_back(key);
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < (int)in[i].size(); ++j) ans += j * in[i][j];
    }
    cur = ans;
    int S = 0, ptr = (int)in[1].size() - 1;
    for (int j = (int)d.size() - 1; j >= 0; --j) {
        int block = d[j] % k + 1;
        int val = a[d[j]];
        in[block].pop_back();
        cur -= (int)in[block].size() * val;
        while (ptr >= 0 && in[1][ptr] >= val) {
            S += in[1][ptr];
            ptr--;
        }
        cur += val * (ptr + 1);
        cur += S;
        S += val;
        ans = max(ans, cur);
    }
    cout << ans << '\n';
    return 0;
}