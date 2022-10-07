#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int n;
int p[N];
int t[N];
int val[N];
int mn[N * 4];
int pl[N * 4];
int id[N * 4];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]); p[i]--;
        scanf("%d", &t[i]);
        if (t[i] == 1) 
            scanf("%d", &val[i]);
    }
}

void add(int v, int tl, int tr, int pos, int type, int x) {
    if (tl + 1 == tr) {
        id[v] = x;
        if (type == 0) {
            mn[v] = 1;
        } 
        else {
            pl[v] = 1;
        }
        return;
    }
    if (pos < (tl + tr) / 2)
        add(v * 2 + 1, tl, (tl + tr) / 2, pos, type, x);
    else
        add(v * 2 + 2, (tl + tr) / 2, tr, pos, type, x);

    mn[v] = mn[v * 2 + 1];
    pl[v] = pl[v * 2 + 2];
    int tmp = pl[v * 2 + 1] - mn[v * 2 + 2];
    if (tmp >= 0)
        pl[v] += tmp;
    else
        mn[v] += abs(tmp);
}

int get(int v, int tl, int tr, int cnt) {
    //cerr << "v tl tr cnt: " << v << " " << tl << " " << tr << " " << cnt << endl;
    assert(cnt >= 1);
    assert(pl[v] >= cnt); 
    if (tl + 1 == tr) {
        return id[v];
    }
    if (cnt <= pl[v * 2 + 2])
        return get(v * 2 + 2, (tl + tr) / 2, tr, cnt);
    //db2(pl[v * 2 + 2], mn[v * 2 + 2]);
    //db(cnt);
    //db3(cnt, pl[v * 2 + 2], mn[v * 2 + 2]);
    //int x = cnt - pl[v * 2 + 2] + mn[v * 2 * 2];
    //db(cnt - pl[v * 2 + 2] + mn[v * 2 * 2]);
    //db3(cnt, - pl[v * 2 + 2], + mn[v * 2 * 2]);
    //db(x);
    return get(v * 2 + 1, tl, (tl + tr) / 2, cnt - pl[v * 2 + 2] + mn[v * 2 + 2]);
}

void solve() {
    for (int i = 0; i < n; i++) {
        //id[p[i]] = val[i];
        add(0, 0, n, p[i], t[i], val[i]);

        //for (int j = 0; j < n * 4; j++)
            //db3(j, mn[j], pl[j]);
        //db2(mn[0], pl[0]);
        if (pl[0] == 0) {
            puts("-1");
        }
        else {
            printf("%d\n", get(0, 0, n, 1));
        }
    }


}

void stress() {

}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    if (1) {
        read();
        solve();
    }
    else {
        stress();
    }

    return 0;
}