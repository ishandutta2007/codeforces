#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll> > mat;

const ld PI = acos(-1);
const ll INF = 1e15 + 10;
const int LOG = 30;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 10;

map<int, int> m;

void factorize(int x) {
    while (x > 1) {
        for (int i = 2; i * i <= x; i++) {
            int alpha = 0;
            while (x % i == 0) {
                alpha++;
                x /= i;
            }
            if (alpha) {
                m[i] |= (1 << (alpha - 1));
            }
        }
        if (x > 1) {
            int alpha = 1;
            m[x] |= (1 << (alpha - 1));
            x = 1;
        }
    }
}

map<int, int> grundyVals;

int grundy(int mask) {
    if (!mask)
        return 0;
    if (grundyVals.count(mask))
        return grundyVals[mask];

    set<int> vals;

    int minBit = -1;
    for (int i = 0; i < LOG; i++)
        if (mask & (1 << i)) {
            minBit = i;
            break;
        }
    vals.insert(grundy(mask >> (minBit + 1)));

    for (int i = 0; i < LOG; i++) {
        int mask2 = (mask & ((1 << i) - 1)) | (mask >> (i + 1));
        if (mask2 != mask)
            vals.insert(grundy(mask2));
    }

    int mex = 0;
    while (vals.size() && *vals.begin() == mex) {
        mex++;
        vals.erase(vals.begin());
    }
    return grundyVals[mask] = mex;
}

int a[N];

void solve() {
    int n;
    cin >> n;
    m.clear();
    fr(i, n) {
        cin >> a[i];
        factorize(a[i]);
    }

    int ans = 0;
    for (auto x: m) {
        ans ^= grundy(x.second);
    }

    if (ans) {
        cout << "Mojtaba\n";
    } else {
        cout << "Arpa\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    int t = 1;
    while (t--)
        solve();

}