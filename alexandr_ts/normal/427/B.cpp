#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define SSTR(x) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e6 + 10;
const ld EPS = 1e-13;
const ll INF = 2 * 1e9 + 1;
const ll MAX = 1e9;

int t[N];
int a[N];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = max(t[2 * v], t[2 * v + 1]);
}

int getMax(int v, int tl, int tr, int l, int r) {
    if (tl > r || tr < l)
        return -INF;
    if (l <= tl && tr <= r)
        return t[v];
    int tm = (tl + tr) / 2;
    return max(getMax(2 * v, tl, tm, l, r), getMax(2 * v + 1, tm + 1, tr, l, r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    int n, t1, c;
    cin >> n >> t1 >> c;
    fill(t, t + 4 * n + 1, -INF);
    fr(i, n)
        cin >> a[i];
    build(1, 0, n - 1);
    int q = 0;
    fr(i, n - c + 1) {
        //cout << getMax(1, 0, n - 1, i, i + c - 1) << endl;
        if (getMax(1, 0, n - 1, i, i + c - 1) <= t1)
            q++;
    }
    cout << q;
}