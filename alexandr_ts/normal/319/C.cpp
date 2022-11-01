#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ld, ld> pl;

const ll INF = 1e9;
const ld EPS = 1e-8;
const ll MAX = 1e6;
const int N = 1e5 + 2;

ll a[N], b[N];
ll d[N];

bool above(pl pt, pl line) {
    return line.first * pt.first + line.second < pt.second;
}

pl inter(pl l1, pl l2) {
    ld x = ((l2.second - l1.second) / (l1.first - l2.first));
    return {x, x * l2.first + l2.second};
}

vector <pl> p;
vector <pl> l = {{INF, INF * INF}};

void add(ll k, ll b) {
    pl newl = mp(k, b);
    while (p.size() && above(p.back(), newl)) {
        p.pop_back();
        l.pop_back();
    }
    p.push_back(inter(newl, l.back()));
    l.push_back(newl);
}

bool cmp(pl a, pl b) {
    //return a.first > b.first;
}

ll get(ll x) {
//    for (auto t: p) cout << t.first << " ! " << t.second << endl;
//    cout << endl;
    int i = lower_bound(p.begin(), p.end(), mp((ld)x, -(ld)INF)) - p.begin();
    return (ll)(l[i].first * x + l[i].second + EPS);
}

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    for (int i = 0; i < n; i++)
        scanf("%d", b + i);

    d[0] = 0;
    add(b[0], 0);
    for (int i = 1; i < n; i++) {
        d[i] = get(a[i]);
        add(b[i], d[i]);
        //cout << i << " " << d[i] << endl;
    }
    cout << d[n - 1];
}