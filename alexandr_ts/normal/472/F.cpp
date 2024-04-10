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
const int INF = 1e9;
const int N = 1e4 + 1;
const int LOG = 30;

vector<int> inds[N];
vector<pair<int, int> > answer[2];

int a[N], b[N];

void f(int* a, int i, int j, int ai) {
    answer[ai].pb({i, j});
    a[i] ^= a[j];
    //cout << i << " " << j << " ar: " << ai << endl;
}

vector<int> gauss(int* a, int n, int ai) {
    vector<int> bits;

    int cntFound = 0;
    for (int lg = LOG - 1; lg >= 0; lg--) {
        int pos = -1;
        for (int i = cntFound; i < n; i++) {
            if (a[i] & (1 << lg)) {
                pos = i;
                break;
            }
        }
        if (pos != -1) {
            bits.pb(lg);
            if (cntFound != pos) {
                f(a, cntFound, pos, ai);
                f(a, pos, cntFound, ai);
                f(a, cntFound, pos, ai);
            }
            for (int i = 0; i < n; i++)
                if (cntFound != i && (a[i] & (1 << lg))) {
                    f(a, i, cntFound, ai);
                }
            cntFound++;
        }
    }
    return bits;
}

int a_r[N], b_r[N];

void solve() {
    int n;
    cin >> n;
    fr(i, n) {
        cin >> a[i];
        a_r[i] = a[i];
    }

    auto bitsa = gauss(a, n, 0);

    fr(i, n) {
        cin >> b[i];
        b_r[i] = b[i];
    }

    auto bitsb = gauss(b, n, 1);

//    cout << "bitsa: ";for (auto x: bitsa) cout << x << " ";cout << endl;
//    cout << "bitsb: ";for (auto x: bitsb) cout << x << " ";cout << endl;

    if (bitsb.size() > bitsa.size()) {
        cout << -1 << "\n";
        return;
    }

    for (int i = 0; i < bitsb.size(); i++) {
        if (!(b[i] & (1 << bitsa[i]))) {
            f(a, i, i, 0);
        }
        for (int j = i + 1; j < bitsa.size(); j++) {
            if (b[i] & (1 << bitsa[j])) {
                f(a, i, j, 0);
            }
        }
    }
    for (int i = (int)bitsb.size(); i < (int)bitsa.size(); i++) {
        f(a, i, i, 0);
    }

    reverse(answer[1].begin(), answer[1].end());
    for (auto x: answer[1])
        answer[0].pb(x);

    for (auto x: answer[0]) {
        a_r[x.first] ^= a_r[x.second];
    }

    for (int i = 0; i < n;i++)
    if (a_r[i] != b_r[i]) {
        cout << "-1\n";
        return;
    }

    cout << answer[0].size() << "\n";
    for (auto x: answer[0])
        cout << x.first + 1 << " " << x.second + 1 << "\n";


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    solve();

}