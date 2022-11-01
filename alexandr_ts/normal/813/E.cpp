#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 7;
const int M = 321;
const int N = 1e5 + 10;
const int POW = 20;

int a[N], lft[N], rgt[N], tmp[N];
pair <int, int> ks[N];

vector <int> t[4 * N];

void build(int v, int tl, int tr, int k) {
    if (tl == tr) {
        if (ks[tl].first == k)
            t[v].pb(ks[tl].second);
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm, k);
    build(2 * v + 1, tm + 1, tr, k);
    t[v].resize(t[2 * v].size() + t[2 * v + 1].size());
    merge(t[2 * v].begin(), t[2 * v].end(), t[2 * v + 1].begin(), t[2 * v + 1].end(),
          t[v].begin());
}

int get(int v, int tl, int tr, int l, int r) {
    if (l > tr || r < tl) return 0;
    if (l <= tl && tr <= r) {
        return upper_bound(t[v].begin(), t[v].end(), r) - t[v].begin();
    }
    int tm = (tl + tr) / 2;
    return get(2 * v, tl, tm, l, r) +
        get(2 * v + 1, tm + 1, tr, l, r);
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    fr(i, n)
        cin >> a[i];

    fill(tmp, tmp + N, -1);

    fill(lft, lft + n, -1);
    fill(rgt, rgt + n, -1);

    fr(i, n) {
        if (tmp[a[i]] != -1)
            lft[i] = tmp[a[i]];
        tmp[a[i]] = i;
    }

    fill(tmp, tmp + N, -1);
    for (int i = n - 1; i >= 0; i--) {
        if (tmp[a[i]] != -1)
            rgt[i] = tmp[a[i]];
        tmp[a[i]] = i;
    }

    fill(ks, ks + n, mp(-1, -1));

    for (int i = n - 1; i >= 0; i--) {
        if (rgt[i] == -1)
            ks[i] = mp(0, -1);
        else if (ks[rgt[i]].first == 0) {
            ks[i] = mp(1, rgt[i]);
        }
        else
            if (ks[rgt[i]].first == k) {
                ks[i] = mp(k, lft[ks[rgt[i]].second]);
            }
            else {
                ks[i] = mp(ks[rgt[i]].first + 1, ks[rgt[i]].second);
            }
    }
//    fr(i, n)  cout << lft[i] << " ";cout << endl;
//    fr(i, n)  cout << rgt[i] << " ";cout << endl;
//    fr(i, n)
//        cout << ks[i].first << " " << ks[i].second << endl;

    build(1, 0, n - 1, k);


    int last = 0;
    int q;
    cin >> q;
    fr(i, q) {
        int xi, yi;
        cin >> xi >> yi;
        int li = ((xi + last) % n) + 1;
        int ri = ((yi + last) % n) + 1;
        if (li > ri) swap(li, ri);
        //cout << li << " " << ri << endl;
        int ans = (ri - li + 1) - get(1, 0, n - 1, li - 1, ri - 1);
        last = ans;
        cout << ans << endl;
    }
}