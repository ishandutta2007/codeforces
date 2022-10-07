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
    pnt operator + (pnt A) {
        return pnt(x + A.x, y + A.y);
    }
    pnt operator - (pnt A) {
        return pnt(x - A.x, y - A.y);
    }
    long long operator * (pnt A) {
        return x * A.y - y * A.x;
    }
    long long operator % (pnt A) {
        return x * A.x + y * A.y;
    }
    void read() {
        scanf("%lld%lld", &x, &y);
    }
    long long len2() {
        return x * x + y * y;
    }
    bool operator == (pnt A) {
        return x == A.x && y == A.y;
    }
};

int n;
pnt a[N];
pnt A;
pnt O;
pnt st[N];

void read() {
    scanf("%d", &n);
    A.read();
    for (int i = 0; i < n; i++)
        a[i].read();
}

bool cmpO(pnt A, pnt B) {
    A = A - O;
    B = B - O;
    return (A * B > 0) || (A * B == 0 && A.len2() < B.len2());
}

void convexHull() {
    long long mxX = 0;
    long long mxY = 0;
    for (int i = 0; i < n; i++)  {
        mxX = max(mxX, a[i].x);
        mxY = max(mxY, a[i].y);
    }
    a[n] = pnt(mxX, 0);
    a[n + 1] = pnt(0, mxY);
    swap(a[n], a[0]);

    n += 2;

    O = a[0];
    sort(a + 1, a + n, cmpO);
    int cur = 0;
    bool flag = 0;
    for (int i = 0; i < n; i++) {
        for (; cur >= 2 && (st[cur - 1] - st[cur - 2]) * (a[i] - st[cur - 1]) <= 0; cur--);
        st[cur++] = a[i];
        if (a[i] == pnt(0, mxY)) {
            flag = 1;
            break;
        }
    }
    assert(flag); 
    for (int i = 0; i + 1 < cur; i++) {
        if (st[i] * A >= 0 && A * st[i + 1] >= 0) {
            double r1 = (A - st[i]) * (st[i + 1] - st[i]);
            double r2 = (st[i + 1] - st[i]) * (pnt(0, 0) - st[i]);
            double answer = r1 / r2 + 1;
            printf("%.17f\n", answer);
            return;
        }

    }
    assert(false);

}

void solve() {
    convexHull();


}

void printAns() {

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
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}