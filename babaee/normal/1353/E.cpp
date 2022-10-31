/*
    Soheil Mohammadkhani
    Div3. Contest :|
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define debug2(x)                   cerr << #x << ": " <<  x <<  " ";
#define debug_p(x)                  cerr << #x << ": " <<  x.X <<  " " << x.Y << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll a[MAXN];


pll maxSubArraySum(vector<ll> v, ll sz)
{
    ll max_so_far = INT_MIN, max_ending_here = 0,
       start =0, en = 0, s=0;

    ll i = 0;
    for (ll e : v)
    {
        max_ending_here += e;

        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            en = i;
        }

        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }

        i++;
    }

    return {max_so_far, (en - start + 1)};
}

ll solve() {
    // X: size, Y: End
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    ll qq = 0;
    ll no = 0;
    for (char c : s) {
        if (c == '1') {
            a[qq] = 1;
            no++;
        } else {
            a[qq] = -1;
        }

        qq++;
    }

    ll ans = max(no - 1, 0ll);
    for (int j = 0; j < k; j++) {
        vector<ll> v;
        for (int i = j; i < n; i += k) {
            v.push_back(a[i]);
        }

        pll p = maxSubArraySum(v, SZ(v));
//        alog(v, SZ(v));
        ll tans = no - p.X;
        ans = min(ans, tans);
    }

    cout << ans << endl;
    return 0;
}

int main() {
    fast_io;


//    cout << med(3, 5) << endl;
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}