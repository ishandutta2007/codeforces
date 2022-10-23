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
        int n, k;
        cin >> n >> k;
        if (k == n - 1)
        {
            if (n == 4)
            {
                cout << "-1\n";
                continue;
            }
            cout << n - 1 << " " << n - 2 << "\n" << n -  3 << " 1\n0 2\n";
            for (int i = 3; i < n / 2; ++i) cout << i << " " << n - 1 - i << "\n";
            continue;
        }
        else if (k == 0)
        {
            for (int i = 0; i < n / 2; ++i) cout << i << " " << n - 1 - i << "\n";
            continue;
        }
        cout << n - 1 << " " << k << "\n" << n - 1 - k << " 0\n";
        for (int i = 1; i < n / 2; ++i)
            if (i != k && i != n - 1 - k) cout << i << " " << n - 1 - i << "\n";
    }
    return 0;
}