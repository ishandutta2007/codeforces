#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

const int N = 100005;
const int BL = 2154;

struct Query1 { 
    int t, l, r, id;
} q1[N];

struct Query2 {
    int p, fr, to;
} q2[N];

int L, R, T;
int n, q, a[N], tmp[N], cnt[2 * N];
int ans[N];
int check[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    // freopen("a.txt", "r", stdin);
    // freopen("c.txt", "w", stdout);
    memset(ans, - 1, sizeof(ans));
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tmp[i] = a[i];
    }
    int nChange = 0;
    int nQue = 0;
    for (int i = 1; i <= q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            ++nQue;
            Query1 &ref = q1[nQue];
            cin >> ref.l >> ref.r;
            ref.t = nChange;
            ref.id = i;
        } else {
            ++nChange;
            Query2 &ref = q2[nChange];
            cin >> ref.p >> ref.to;
            ref.fr = a[ref.p];
            a[ref.p] = ref.to; 
        }
    }
    set<int> s;
    map<int, int> cmp;
    for (int i = 1; i <= n; i++) {
        a[i] = tmp[i];
        s.insert(a[i]);
    }
    for (int i = 1; i <= nChange; i++) {
        s.insert(q2[i].to);
    }
    int curComp = 0;
    for (int e : s) {
        cmp[e] = curComp++;
    }
    for (int i = 1; i <= n; i++) {
        a[i] = cmp[a[i]];
    }
    for (int i = 1; i <= nChange; i++) {
        q2[i].fr = cmp[q2[i].fr];
        q2[i].to = cmp[q2[i].to];
    }
    sort(q1 + 1, q1 + nQue + 1, [](Query1 le, Query1 ri) {
        if (le.t / BL != ri.t / BL) return le.t / BL < ri.t / BL;
        if (le.l / BL != ri.l / BL) return le.l / BL < ri.l / BL;
        return le.r < ri.r;
    });
    L = 1, R = 0, T = 0;
    for (int i = 1; i <= nQue; i++) {
        int l = q1[i].l;
        int r = q1[i].r;
        int t = q1[i].t;
        while (R < r) {
            R++;
            check[cnt[a[R]]]--;
            cnt[a[R]]++;
            check[cnt[a[R]]]++;
        }
        while (L > l) {
            L--;
            check[cnt[a[L]]]--;
            cnt[a[L]]++;
            check[cnt[a[L]]]++;
        }
        while (R > r) {
            check[cnt[a[R]]]--;
            cnt[a[R]]--;
            check[cnt[a[R]]]++;
            R--;
        }
        while (L < l) {
            check[cnt[a[L]]]--;
            cnt[a[L]]--;
            check[cnt[a[L]]]++;
            L++;
        }
        while (T < t) {
            T++;
            if (q2[T].p >= l && q2[T].p <= r) {
                check[cnt[q2[T].fr]]--;
                cnt[q2[T].fr]--;
                check[cnt[q2[T].fr]]++;
                check[cnt[q2[T].to]]--;
                cnt[q2[T].to]++;
                check[cnt[q2[T].to]]++;
            }
            a[q2[T].p] = q2[T].to;
        }
        while (T > t) {
            if (q2[T].p >= l && q2[T].p <= r) {
                check[cnt[q2[T].to]]--;
                cnt[q2[T].to]--;
                check[cnt[q2[T].to]]++;
                check[cnt[q2[T].fr]]--;
                cnt[q2[T].fr]++;
                check[cnt[q2[T].fr]]++;
            }
            a[q2[T].p] = q2[T].fr;
            T--;
        }
        for (int j = 1; j <= 100000; j++) {
            if (check[j] == 0) {
                ans[q1[i].id] = j;
                break;
            }
        }
        // cout << q1[i].id << ' ';
        // for (int i = 0; i <= 3; i++) {
        //     cout << cnt[i] << ' ';
        // }
        // cout << endl;
        // for (int i = 1; i <= 3; i++) {
        //     cout << check[i] << ' ';
        // }
        // cout << endl;
    }
    for (int i = 1; i <= q; i++) {
        if (ans[i] != -1) cout << ans[i] << '\n';
    }
    return 0;
}