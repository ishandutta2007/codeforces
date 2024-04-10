#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;
const long long gs = 500 * kk;

ll n, m, i, j, ans;
vector<ll> reb[gs + 10];
vector<ll> col, tc, p, s, q;
bool viv = false;

void DFS(ll v, ll c) {
    col[v] = c;
    ll l = reb[v].size();
    for (ll i = 0; i < l; i++) {
        ll s = reb[v][i];
        if (col[s] == -1) {
            DFS(s, c  +1);
        }
    }
    q.push_back(v);
}

void work(ll v) {
    ll v1 = s[p[v]];
    vector<ll> k;
    for (auto ss : reb[v])
        if (ss != p[v])
            k.push_back(s[ss]);
    ll z = v1;
    if (k.size())
        z = *min_element(k.begin(), k.end());
//    cout << v << ' ' << v1 << ' ' << z << endl;
    if (z < v1) {
        cout << -1 << endl;
        exit(0);
    }
    s[v] = z;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    m = n-1;
    p.resize(n);
    for (i = 1; i < n; i++) {
        long a, b;
        cin  >> b;
        b--;
        a = i;
        swap(a, b);
        p[b] = a;
        reb[a].push_back(b);
        reb[b].push_back(a);
    }
    col.assign(n, -1);
    s.resize(n);
    for (auto &i : s)
        cin >> i;
    DFS(0, 0);

    ans = s[0];
    for (auto i : q)
        if (s[i] == -1)
            work(i);
    for (ll i = 1; i < n; i++)
        ans += s[i] - s[p[i]];
    cout << ans;


    return 0;
}