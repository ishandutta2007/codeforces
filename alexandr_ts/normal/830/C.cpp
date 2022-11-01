#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1000000007;
const ll P1 = 17;
const ll P2 = 19;
const ld PI = acos(-1);
const ll MAX = 63211236 + 10;
const ll INF = 1e9 + 10;
const ld EPS = 1e-9;
const int M = 4e5;
const int N = 1e6 + 10;

ll a[N];

bool solve(int n, ll d, ll k) {
    ll sum = 0;
    fr(i, n)
        sum += d - ((a[i] - 1) % d + 1);
    return sum <= k;
}

int main() {
    //freopen("a.in", "r", stdin);
    ll n, k;
    cin >> n >> k;
    fr(i, n)
        cin >> a[i];
    vector <ll> cands;
    frab(i, 1, M)
        cands.pb(i);
    ll s = accumulate(a, a + n, 0ll);
    frab(sum, 1, M) {
        ll c = (s + k) / sum;
        if (c >= M)
            cands.pb(c);
        else
            break;
    }
    sort(cands.begin(), cands.end());

    for (int i = (int)cands.size() - 1; i >= 0; i--)
        if (solve(n, cands[i], k)) {
            cout << cands[i];
            return 0;
        }
    assert(false);
}