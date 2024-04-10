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
        int v = 0;
        int n;
        cin >> n;
        for (int i = 1, x; i <= n; ++i) cin >> x, v ^= (x - 1) & 1;
        if (v) cout << "errorgorn\n";
        else cout << "maomao90\n";
    }
    return 0;
}