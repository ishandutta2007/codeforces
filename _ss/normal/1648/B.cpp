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

const int N = 1e6 + 10;

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        vi a(c + 1, 0);
        for (int i = 1, x; i <= n; ++i) cin >> x, a[x] = 1;
        for (int i = 1; i <= c; ++i) a[i] += a[i - 1];
        bool check = false;
        for (int i = 1; i <= c; ++i)
            if (a[i] - a[i - 1] == 0)
                for (int j = 1; j <= c / i; ++j)
                    if (a[j] - a[j - 1] > 0)
                    {
                        int l = i * j, r = min(l + j - 1, c);
                        if (a[r] - a[l - 1] > 0) check = true;
                    }
        if (!check) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}