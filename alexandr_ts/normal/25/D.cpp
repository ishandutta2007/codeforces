#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e4 + 50;
const ll M = 1e6 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-9;

int v1[N], v2[N], rnk[N], par[N];

void build(int v) {
    rnk[v] = 1;
    par[v] = v;
}

int Find(int v) {
    if (par[v] == v) return v;
    int t = Find(par[v]);
    par[v] = t;
    return t;
}

void Union(int a, int b) {
    int a1 = Find(a);
    int b1 = Find(b);
    if (a1 == b1) return;
    if (rnk[a1] < rnk[b1])
        swap(a1, b1);
    par[b1] = a1;
    if (rnk[a1] == rnk[b1])
        rnk[a1]++;
}

int main() {
    //freopen("a.in", "r", stdin);
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    fr(i, n - 1) {
        cin >> v1[i] >> v2[i];
        v1[i]--, v2[i]--;
    }

    fr(i, n)
        build(i);

    vector <int> useless;
    fr(i, n - 1) {
        if (Find(v1[i]) != Find(v2[i]))
            Union(v1[i], v2[i]);
        else
            useless.pb(i);
    }
    cout << useless.size() << endl;
    int cur = 0;
    fr(i, n)
        if (Find(0) != Find(i)) {
            //cout << i << endl;
            cout << v1[useless[cur]] + 1 << " " << v2[useless[cur]] + 1 <<
                " " << 1 << " " << i + 1 << endl;
            Union(0, i);
            cur++;
        }


}