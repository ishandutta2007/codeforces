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
int a[N], b[N], n;

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];
        int flag = 1;
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);
        for (int i = 1; i <= n; ++i)
            if (b[i] - a[i] < 0 || b[i] - a[i] > 1) flag = 0;
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}