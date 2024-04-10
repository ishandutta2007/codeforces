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

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll lcm = 1;
        int flag = 1;
        for (int i = 1, x; i <= n; ++i)
        {
            cin >> x;
            if (lcm <= 1e9) lcm = lcm * (i + 1) / __gcd(lcm, (ll)i + 1);
            if (x % lcm == 0) flag = 0;
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}