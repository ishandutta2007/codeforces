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
        vi a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        while (n >= 1 && a[n] == 0) n--;
        bool check = true;
        ll sum = 0;
        a[1]--;
        a[n]++;
        for (int i = n; i; --i)
        {
            sum -= a[i];
            if (sum < 0) check = false;
        }
        if (sum != 0) check = false;
        if (check) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}