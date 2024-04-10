#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 10;
const int INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;

int a[N], t[N], x[N], b[N];

map <int, int> t1[4 * N];

void add(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        t1[v][val]++;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        add(2 * v, tl, tm, pos, val);
    else
        add(2 * v + 1, tm + 1, tr, pos, val);
    t1[v][val]++;
}

void del(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        t1[v][val]--;
        //if (t1[v][val] < 0)
        //    cout << t1[v][val] << " " << pos << "  " << v << " " << val << endl;
       // assert(t1[v][val] >= 0);
        //if (t1[v][val] == 0)
        //    t1[v].erase(val);
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        del(2 * v, tl, tm, pos, val);
    else
        del(2 * v + 1, tm + 1, tr, pos, val);
    t1[v][val]--;
    //assert(t1[v][val] >= 0);
    //if (t1[v][val] == 0)
     //   t1[v].erase(val);
}

int sum(int v, int tl, int tr, int l, int r, int val) {
    if (tl > r || tr < l)
        return 0;
    if (l <= tl && tr <= r)
        if (t1[v].count(val))
            return t1[v][val];
        else
            return 0;
    int tm = (tl + tr) / 2;
    return sum(2 * v, tl, tm, l, r, val) + sum(2 * v + 1, tm + 1, tr, l, r, val);
}

int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, cur = 0;
    cin >> n;
    unordered_map <int, int> tmp;
    fr(i, n) {
        scanf("%d %d %d", &a[i], &t[i], &x[i]);
        //cin >> a[i] >> t[i] >> x[i];
        b[cur++] = t[i];
    }
    sort(b, b + n);
    fr(i, n)
        tmp[b[i]] = i;
    fr(i, n)
        t[i] = tmp[t[i]];
    fr(i, n) {
        if (a[i] == 1)
            add(1, 0, n - 1, t[i], x[i]);
        else if (a[i] == 2)
            del(1, 0, n - 1, t[i], x[i]);
        else {
            int ans = sum(1, 0, n - 1, 0, t[i], x[i]);
            printf("%d\n", ans);
        }
    }
}