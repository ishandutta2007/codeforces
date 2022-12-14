/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author alireza_kaviani
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, A[MAXN], ps[MAXN], mnInd[MAXN];
double pa[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (ll i = 1; i <= n; i++) cin >> A[i];
    for (ll i = 1; i <= n; i++) ps[i] = ps[i - 1] + A[i];
    for (ll i = 1; i <= n; i++) pa[i] = double(ps[i]) / double(i);

    mnInd[n] = n;
    for (ll i = n - 1; i >= 1; i--) {
        ll j = i;
        double sm = A[i], avg = A[i];
        while (j < n) {
            if (avg > (ps[mnInd[j + 1]] - ps[i - 1]) / double(mnInd[j + 1] - i + 1)) {
                avg = (ps[mnInd[j + 1]] - ps[i - 1]) / double(mnInd[j + 1] - i + 1);
                j = mnInd[j + 1];
            } else break;
        }
        mnInd[i] = j;
    }
    for (ll i = 1; i <= n; i++) {
        double avg = double(ps[mnInd[i]] - ps[i - 1]) / double(mnInd[i] - i + 1);
        for (ll j = i; j <= mnInd[i]; j++) printf("%.15f\n", avg);
        i = mnInd[i];
    }

    return 0;
}
/*

*/