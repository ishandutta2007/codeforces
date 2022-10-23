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
int a[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        map<int, int> cnt;
        int n;
        cin >> n;
        for (int i = 1, x; i <= n; ++i) cin >> x, cnt[x]++, a[i] = x;
        int mx = 0;
        for (pii pa : cnt) mx = max(mx, pa.se);
        if (n % 2 == 0 && (mx < n / 2 || (mx == n / 2 && (cnt.begin()->se == n / 2 || prev(cnt.end())->se == n / 2))))
        {
            sort(a + 1, a + n + 1);
            cout << "YES\n";
            for (int i = 1; i <= n / 2; ++i) cout << a[i] << " " << a[i + n / 2] << " ";
            cout << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}