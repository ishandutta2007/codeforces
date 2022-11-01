#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll> > mat;

const ll INF = 1e9 + 10;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 10;

vector<int> pos[N];
int a[N];
int leftr[N];

void solve() {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].pb(i);
    }

    leftr[x + 1] = INF;
    for (int i = x; i >= 1; --i) {
        leftr[i] = leftr[i + 1];
        if (pos[i].size())
            leftr[i] = min(leftr[i], pos[i][0]);
    }

    int tmp = INF;
    int minr = x;
    for (; minr >= 1; minr--) {
        if (pos[minr].size()) {
            if (tmp < pos[minr].back())
                break;
            tmp = min(tmp, pos[minr][0]);
        }
    }

   // cout << "minr: " << minr << endl;

    ll ans = 0;

    int curr = minr;
    int lastl = -1;
    for (int l = 1; l <= x; l++) {

        curr = max(curr, l);
        while (leftr[curr + 1] < lastl)
            curr++;

        //if (curr > minr) break;

        //cout << l << " " << (x - curr + 1) << " " << curr << endl;

        ans += (x - curr + 1);

        if (pos[l].size() && lastl > pos[l][0])
            break;
        if (pos[l].size())
            lastl = max(lastl, pos[l].back());
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    int t = 1;
    while (t--)
        solve();
}