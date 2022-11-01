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
const int N = 2e5 + 10;

vector<int> both, a, b, none;

int c[N];

bool isa[N], isb[N];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    int cnta1, cntb1;
    cin >> cnta1;
    for (int i = 0; i < cnta1; i++) {
        int num;
        cin >> num;
        isa[num - 1] = true;
    }
    cin >> cntb1;
    for (int i = 0; i < cntb1; i++) {
        int num;
        cin >> num;
        isb[num - 1] = true;
    }
    for (int i = 0; i < n; i++) {
        if (isa[i] && isb[i]) {
            both.pb(c[i]);
        } else if (isa[i]) {
            a.pb(c[i]);
        } else if (isb[i]) {
            b.pb(c[i]);
        } else {
            none.pb(c[i]);
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(none.begin(), none.end());
    sort(both.begin(), both.end());

//    cout << "both: ";for (auto x: both) cout << x << " ";cout << endl;
//    cout << "a: ";for (auto x: a) cout << x << " ";cout << endl;
//    cout << "b: ";for (auto x: b) cout << x << " ";cout << endl;
//    cout << "none: ";for (auto x: none) cout << x << " ";cout << endl;


    ll sumBoth = 0;
    int cntA = (int)a.size();
    int cntB = (int)b.size();
    ll sumA = accumulate(a.begin(), a.end(), 0ll);
    ll sumB = accumulate(b.begin(), b.end(), 0ll);

    multiset<int, greater<int>> mins;
    multiset<int> maxs;
    ll sumMins = 0;
    ll ans = INF;

    for (auto x: none) {
        sumMins += x;
        mins.insert(x);
    }

    for (int cntBoth = 0; cntBoth <= (int)both.size(); cntBoth++) {
        while (cntA > 0 && cntA - 1 >= k - cntBoth) {
            cntA--;
            sumMins += a[cntA];
            sumA -= a[cntA];
            mins.insert(a[cntA]);
        }
        while (cntB > 0 && cntB - 1 >= k - cntBoth) {
            cntB--;
            sumMins += b[cntB];
            sumB -= b[cntB];
            mins.insert(b[cntB]);
        }

        int lft = m - cntBoth - cntA - cntB;

        for (int i = 0; i < 3; i++) {
            if (maxs.size()) {
                auto it = maxs.begin();
                sumMins += *it;
                mins.insert(*it);
                maxs.erase(it);
            }
        }

        while (mins.size() > lft) {
            sumMins -= *mins.begin();
            maxs.insert(*mins.begin());
            mins.erase(mins.begin());
        }

        if (mins.size() == lft && cntBoth + min(cntA, cntB) >= k) {
            ans = min(ans, sumMins + sumA + sumB + sumBoth);
        }

        if (cntBoth < (int)both.size())
            sumBoth += both[cntBoth];
    }

    if (ans == INF)
        cout << -1;
    else
        cout << ans;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    solve();

}