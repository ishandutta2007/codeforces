#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 7;
const int M = 1501;
const int POW = 20;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e4 + 10;

struct Pt {
    ll x, y, r;
} a[N];

vector <int> g[N], g2[N];

bool in1(Pt a, Pt b) {
    return b.r > a.r && b.r * b.r > (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int koef[N];

void dfs(int v, int k) {
    koef[v] = k;
    for (auto t: g[v])
        dfs(t, -k);
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i].x >> a[i].y >> a[i].r;

    fr(i, n) {
        int num = -1;
        fr(j, n)
            if (i != j && in1(a[i], a[j]))
                if (num == -1 || a[num].r > a[j].r)
                    num = j;
        //cout << i << " " << num << endl;
        if (num != -1) {
            g[num].pb(i);
            g2[i].pb(num);
        }
    }

    fr(i, n)
        if (g2[i].size() == 0) {
            koef[i] = 1;
            for (auto t: g[i])
                dfs(t, 1);
        }

//    fr(i, n)
//        cout<< koef[i] << " ";cout << endl;
    ll sum = 0;
    //cout << sum << endl;
    fr(i, n)
        sum += a[i].r * a[i].r * koef[i];
    cout << fixed << setprecision(12) << PI * sum;
}