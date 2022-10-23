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

ll ask(int l, int r)
{
    cout << "? " << l << " " << r << endl;
    ll res;
    cin >> res;
    return res;
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll inv = ask(1, n);
        int k = n, l = 1, r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (ask(1, mid) == inv) k = mid, r = mid - 1;
            else l = mid + 1;
        }
        ll inv2 = ask(1, k - 1);
        int j = k - (inv - inv2);
        inv -= (ll)(k - j + 1) * (k - j) / 2;
        int i = j - 1 - (ask(1, j - 1) - ask(1, j - 2));
        cout << "! " << i << " " << j << " " << k << endl;
    }
    return 0;
}