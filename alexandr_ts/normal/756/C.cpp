#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef unsigned long long ll;
typedef long double ld;

const int N = 1e5 + 10;
const int M = 1e7 + 1;
const ll INF = 2000000009;
const ll MOD = 1000*1000*1000 + 7;
const ld EPS = 1e-9;

int tmin[4 * N], tnum[4 * N];

void recalc(int v, int tl, int tr) {
    if (tl == tr)
        return;
    tnum[v] = tnum[2 * v + 1] + max(0, tnum[2 * v] - tmin[2 * v + 1]);
    tmin[v] = tmin[2 * v] + max(0, tmin[2 * v + 1] - tnum[2 * v]);
}

void upd(int v, int tl, int tr, int pos, int typ) {
    if (tl == tr) {
        if (typ == 1)
            tnum[v] = 1;
        else
            tmin[v] = 1;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        upd(2 * v, tl, tm, pos, typ);
    else
        upd(2 * v + 1, tm + 1, tr, pos, typ);
    recalc(v, tl, tr);
}

int get(int v, int tl, int tr, int add) {
    if (!tnum[v])
        return -INF;
    if (tl == tr)
        return tl;
    int tm = (tl + tr) / 2;
    if (tnum[2 * v + 1] > add)
        return get(2 * v + 1, tm + 1, tr, add);
    else
        return get(2 * v, tl, tm, add + tmin[2 * v + 1] - tnum[2 * v + 1]);
}

int ar[N];

int main() {
    //freopen("a.in", "r", stdin);
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i1, n) {
        int p, typ;
        cin >> p >> typ;
        p--;
        if (typ == 1) {
            int x;
            cin >> x;
            upd(1, 0, n - 1, p, 1);
            ar[p] = x;
        }
        else {
            upd(1, 0, n - 1, p, 0);
        }
//        if (i1 == 6) {
//            frab(j, 1, 8)
//                cout << tmin[j] << " " << tnum[j] << endl;
//        }
        //cout << tnum[1] << " " << tmin[1] << endl;
        int ans = get(1, 0, n - 1, 0);
        if (ans == -INF)
            cout << -1;
        else
            cout << ar[ans];
        cout << endl;
    }

}