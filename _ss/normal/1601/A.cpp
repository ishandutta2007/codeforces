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
        vi cnt(30);
        cin >> n;
        for (int i = 1, x; i <= n; ++i)
        {
            cin >> x;
            for (int j = 0; j < 30; ++j)
                if ((x>> j) & 1) cnt[j]++;
        }
        int g = 0;
        for (int i = 0; i < 30; ++i)
            if (cnt[i]) g = __gcd(g, cnt[i]);
        for (int i = 1; i <= n; ++i)
            if (g % i == 0) cout << i << " ";
        cout << "\n";
    }
    return 0;
}