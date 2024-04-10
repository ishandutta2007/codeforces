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

const int N = 2e5 + 10;
int a[N], n, mx[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], mx[a[i]] = max(mx[a[i]], i);
    int res = n, l = 0;
    while (l < n)
    {
        l++;
        int cnt = 1, r = mx[a[l]];
        if (l == r)
        {
            res--;
            continue;
        }
        while (r < n)
        {
            int nr = 0;
            for (int i = l + 1; i < r; ++i)
                nr = max(nr, mx[a[i]]);
            l = r;
            if (nr <= l) break;
            r = nr;
            cnt++;
        }
        l = r;
        res -= cnt + 1;
    }
    cout << res;
    return 0;
}