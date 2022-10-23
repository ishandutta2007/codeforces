#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()
#define i128 __int128
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 1e5 + 10;

bool check(i128 n, i128 k)
{
    if (k < 2) return false;
    i128 d = n - k * (k - 1) / 2;
    return (d >= k && d % k == 0);
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll m = n, d = 2;
        while (m % 2 == 0) m /= 2, d *= 2;
        if (check(n, m)) cout << m << "\n";
        else if (check(n, d)) cout << d << "\n";
        else cout << "-1\n";
    }
    return 0;
}