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

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;

struct pnt {
    long long x, y;
    pnt () { }
    pnt (long long x, long long y): x(x), y(y) { }
};

int n;
pnt v, u;
pnt p[N];
int tree[N * 4];

void read() {
    scanf("%d", &n);
    scanf("%lld/%lld%lld/%lld", &v.y, &v.x, &u.y, &u.x);
    for (int i = 0; i < n; i++)
        scanf("%lld%lld", &p[i].x, &p[i].y);
}

bool cmpRX(pnt A, pnt B) {
    return A.x > B.x || (A.x == B.x && A.y < B.y);
}

int getMax(int v, int ll, int rr, int l, int r) {
    if (l >= rr || ll >= r) return 0;
    if (l <= ll && rr <= r) return tree[v];
    return max(getMax(v * 2 + 1, ll, (ll + rr) / 2, l, r),
               getMax(v * 2 + 2, (ll + rr) / 2, rr, l, r));
}

void add(int v, int ll, int rr, int pos, int val) {
    if (pos < ll || rr <= pos) return;
    if (ll + 1 == rr) {
        tree[v] = max(tree[v], val);
        return;
    }
    add(v * 2 + 1, ll, (ll + rr) / 2, pos, val);
    add(v * 2 + 2, (ll + rr) / 2, rr, pos, val);
    tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
}

void solve() {
    for (int i = 0; i < n; i++) {
        p[i] = pnt(p[i].x * u.y - p[i].y * u.x, v.x * p[i].y - p[i].x * v.y);
    }
    int cur = 0;
    for (int i = 0; i < n; i++)
        if (p[i].x > 0 && p[i].y > 0)
            p[cur++] = p[i];

    n = cur;
    vector < long long > yy;
    for (int i = 0; i < n; i++)
        yy.pb(p[i].y);

    sort(yy.begin(), yy.end());
    yy.resize(unique(yy.begin(), yy.end()) - yy.begin());

    for (int i = 0; i < n; i++)
        p[i].y = lower_bound(yy.begin(), yy.end(), p[i].y) - yy.begin();

    sort(p, p + n, cmpRX); 

    int m = yy.size();
    int answer = 0;
    for (int i = 0; i < n; i++) {
        int res = getMax(0, 0, m, p[i].y + 1, m);
        res++;
        answer = max(answer, res);
        add(0, 0, m, p[i].y, res);
    }
    printf("%d\n", answer);
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}