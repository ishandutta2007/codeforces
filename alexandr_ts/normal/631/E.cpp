#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ld, ld> pl;

const int N = 2e5 + 10;
const ld EPS = 1e-9;
const ll INF = 2e12 + 10;
const ll INFS = 1e9 + 10;

ll a[N], pref[N];

vector <pl> p;
vector <pl> l = {{-1, -INF}};

bool under(pl p, pl l) {
    return p.second < l.first * p.first + l.second;
}

pl inter(pl l1, pl l2) {
    ld x = (l1.second - l2.second) / (l2.first - l1.first);
    return {x, l2.first * x + l2.second};
}

void add(ll k, ll b) {
    pl newl = {k, b};
    while (p.size() && under(p.back(), newl)) {
        p.pop_back();
        l.pop_back();
    }
    p.pb(inter(l.back(), newl));
    l.pb(newl);
}

ld count(ll x, pl l) {
    return l.first * x + l.second;
}

bool cmp(pl a, pl b) {
    return a > b;
}

ll get(ll x, bool rev) {
    int i;
    if (rev)
        i = lower_bound(p.begin(), p.end(), mp((ld)x, -(ld)INF), cmp) - p.begin();
    else
        i = lower_bound(p.begin(), p.end(), mp((ld)x, -(ld)INF)) - p.begin();
    if (i == 0) return -INF;
    return llroundl(count(x, l[i]));
}

ll d[N];
ll d2[N];
ll pref2[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    scanf("%d", &n);
    int temp1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp1);
        a[i + 1] = temp1;
    }
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + a[i];

    add(0, 0);
    ll sum = pref[n];
    ll ad = 0;
    for (int i = 1; i <= n; i++) {
        ad += a[i] * i;
        //cout << i << " " << a[i] << " " << ad << " ad " << i << endl;
    }
    for (int i = 1; i <= n; i++) {
        d[i] = pref[i] - a[i] * i + get(a[i], false);
        //cout << i << " " << d[i] << endl;
        add(i, -pref[i]);
    }

    p.clear();
    l = {{INFS, -INFS * INFS}};
    d2[n + 1] = pref[n];

    for (int i = n; i >= 1; i--) {
        d2[i] = pref[i] - a[i] * i + get(a[i], true);
        add(i, -pref[i]);
        //cout << i << " " << d2[i] << endl;
    }
    ll mx = -INF;
    //cout << ad << endl;
    for (int i = 1; i <= n; i++)
        mx = max(max(mx, d[i]), d2[i]);

    cout << ad + mx << endl;

}