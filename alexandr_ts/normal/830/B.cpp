#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)
#define mp make_pair
#define pb push_back
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e15 + 7;
const int M = 2e6 + 3;
const ld PI = acos(-1);
const int POW = 25;
const ll MOD = 1e9 + 7;

const int N = 1e5 + 10;

ll a[N];

void add(int i, int val, int n) {
    while (i < n) {
        a[i] += val;
        i = (i | (i + 1));
    }
}

ll sumPref(int i) {
    if (i < 0) return 0;
    ll ans = 0;
    while (i >= 0) {
        ans += a[i];
        i = (i & (i + 1)) - 1;
    }
    return ans;
}

ll sum(int l, int r) {
    return sumPref(r) - sumPref(l - 1);
}

vector <int> g[N];

int ar[N];

int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n) {
        cin >> ar[i];
        g[ar[i]].pb(i);
    }

    fr(i, n)
        add(i, 1, n);

    int pos = 0;

    ll ans = 0;

    fr(i, N) {
        if (!g[i].size()) continue;
        //cout << pos << " ";
        int j = 0;
        fr(i1, g[i].size())
            if (g[i][i1] >= pos) {
                j = i1;
                break;
            }
        fr(i1, g[i].size()) {
            if (pos <= g[i][j])
                ans += sum(pos, g[i][j]);
            else
                ans += sum(pos, n - 1) + sum(0, g[i][j]);
            add(g[i][j], -1, n);
            pos = g[i][j];
            j = (j + 1) % g[i].size();
        }
        //cout << i << " " << ans << endl;
    }

    cout << ans;


}