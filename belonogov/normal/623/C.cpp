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
    pnt operator - (pnt A) {
        return pnt(x - A.x, y - A.y);
    }
    long long len2() {
        return x * x + y * y;
    }
};

int n;
pnt p[N];
pnt a[4][N];
long long mxSuf[4][N];
long long mxPref[4][N];
long long mnSuf[4][N];
long long mnPref[4][N];


void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld%lld", &p[i].x, &p[i].y);
}

long long sqr(long long x) {
    return x * x;
}

bool check(long long d) {
    if (d >= sqr(mxPref[0][n] - mnPref[0][n])) return 1;
    if (d >= sqr(mxPref[1][n] - mnPref[1][n])) return 1;

    for (int t = 0; t < 4; t++) {
        int cur = 0; 
        for (int i = 0; i < n; i++) {
            assert(i <= cur);
            for (; cur < n && sqr(a[t][cur].x - a[t][i].x) <= d; cur++);
            if (-a[t][i].x < a[t][cur - 1].x)
                break;
            //cerr << "cur: " << cur << "  ";
            //db2(t, i);
            int mxY = max(mxPref[t][i], mxSuf[t][cur]);
            int mnY = min(mnPref[t][i], mnSuf[t][cur]);
            //db2(mxY, mnY);
            bool flag = 1;
            assert(sqr(a[t][cur - 1].x - a[t][i].x) <= d);
            flag &= sqr(mxY - mnY) <= d;
            //db(flag);
            flag &= sqr(max(abs(mxY), abs(mnY))) + sqr(max(abs(a[t][cur - 1].x), abs(a[t][i].x))) <= d;
            //db(flag);
            if (flag)
                return 1;
        }
    }
    
    return 0;
}

pnt mirror(pnt A) {
    return pnt(-A.x, A.y);
}

bool cmpX(pnt A, pnt B) {
    return A.x < B.x;
}

void solve() {
    long long l = -1;
    long long r = 1e18;
        
    for (int i = 0; i < n; i++) {
        a[0][i] = p[i];
        a[1][i] = pnt(p[i].y, p[i].x);
        a[2][i] = mirror(a[0][i]);
        a[3][i] = mirror(a[1][i]);
    }

    for (int t = 0; t < 4; t++) {
        sort(a[t], a[t] + n, cmpX);
        mxPref[t][0] = -INF;
        mnPref[t][0] = INF;
        for (int i = 0; i < n; i++) {
            mxPref[t][i + 1] = max(mxPref[t][i], a[t][i].y);
            mnPref[t][i + 1] = min(mnPref[t][i], a[t][i].y);
        }
        mxSuf[t][n] = -INF;
        mnSuf[t][n] = INF;
        for (int i = n - 1; i >= 0; i--) {
            mxSuf[t][i] = max(mxSuf[t][i + 1], a[t][i].y);
            mnSuf[t][i] = min(mnSuf[t][i + 1], a[t][i].y);
        }

    }
    //db(check(0));
    //return;

    while (r - l > 1) {
        if (check((l + r) / 2))
            r = (l + r) / 2;
        else
            l = (l + r) / 2;
    }
    
    printf("%lld\n", r);
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