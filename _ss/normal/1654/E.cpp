#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 1e5 + 10;
const int K = 100, C = 1000, offset = 1e7 + 1e5;
int a[N], n, cnt[offset * 2 + 1];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int res = 1;
    for (int d = -K; d <= K; ++d)
    {
        for (int i = 1; i <= n; ++i)
        {
            int val = a[i] - i * d + offset;
            cnt[val]++;
            res = max(res, cnt[val]);
        }
        for (int i = 1; i <= n; ++i) cnt[a[i] - i * d + offset] = 0;
    }
    for (int i = 2; i <= n; ++i)
    {
        for (int j = max(i - C, 1); j < i; ++j)
        {
            int dx = i - j, dy = a[i] - a[j];
            if (dy % dx) continue;
            int val = dy / dx + offset;
            cnt[val]++;
            res = max(res, cnt[val] + 1);
        }
        for (int j = max(i - C, 1); j < i; ++j) cnt[(a[i] - a[j]) / (i - j) + offset] = 0;
    }
    cout << n - res;
    return 0;
}