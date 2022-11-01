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
const ll INF = 1e15 + 10;
const ld EPS = 1e-9;
const int M = 5e3 + 2;
const int N = 5e3 + 5;

int l[N], r[N], l1[N], r1[N];
vector <int> cors;
ll d[2][2 * N];

int f(int i, int j) {
    int j1 = cors[j];
    if (l[i] <= j1 && j1 <= r[i]) return 0;
    return min(abs(l[i] - j1), abs(r[i] - j1));
}

int main() {
    //freopen("a.in", "r", stdin);
    int n, x;
    cin >> n >> x;
    cors.pb(x);
    fr(i, n) {
        cin >> l[i] >> r[i];
        cors.pb(l[i]);
        cors.pb(r[i]);
    }
    sort(cors.begin(), cors.end());
    cors.resize(unique(cors.begin(), cors.end()) - cors.begin());
    int len = cors.size();
    int x1 = lower_bound(cors.begin(), cors.end(), x) - cors.begin();

    fr(i, (int)cors.size())
        d[0][i] = INF;
    d[0][x1] = 0;

    fr(i, n) {
        fill(d[(i + 1) % 2], d[(i + 1) % 2] + len, INF);
        ll tmp = INF;
        fr(j, len) {
            tmp = min(tmp, d[i % 2][j]);
            d[(i + 1) % 2][j] = min(d[(i + 1) % 2][j], tmp + f(i, j));
            if (j + 1 < cors.size())
                tmp += abs(cors[j + 1] - cors[j]);
        }
        tmp = INF;
        for (int j = len - 1; j >= 0; j--) {
            tmp = min(tmp, d[i % 2][j]);
            d[(i + 1) % 2][j] = min(d[(i + 1) % 2][j], tmp + f(i, j));
            if (j)
                tmp += abs(cors[j] - cors[j - 1]);
        }
    }

    ll ans = INF;
    fr(i, len)
        ans = min(ans, d[n % 2][i]);
    assert(ans != INF);
    cout << ans;

}