#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const int INF = 2e9 + 10;
const ld EPS = 1e-9;
const int M = 1e2 + 12;
const int N = 4e5 + 10;

vector <int> v[N];
int a[N], cur[N];

int nxt(int col) {
    if (cur[col] >= v[col].size())
        return INF;
    else
        return v[col][cur[col]];
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    fr(i, n) {
        cin >> a[i];
        v[a[i]].pb(i);
    }

    set <pair <int, int> > s;

    int ans = 0;
    fr(i, n) {
        if (s.count(mp(-nxt(a[i]), a[i]))) {
            s.erase(mp(-nxt(a[i]), a[i]));
            cur[a[i]]++;
            s.insert(mp(-nxt(a[i]), a[i]));
            continue;
        }
        if (s.size() == k) {
            //cout << s.begin()->first << " " << s.begin()->second << endl;
            s.erase(s.begin());
        }
        ans++;
        cur[a[i]]++;
        s.insert(mp(-nxt(a[i]), a[i]));
    }
    cout << ans;

}