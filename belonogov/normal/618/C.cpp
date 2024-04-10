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
    int id;
    pnt () {}
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
};

int n;
pnt p[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &p[i].x, &p[i].y);
        p[i].id = i + 1;
    }
}

bool cmpXY(pnt A, pnt B) {
    return A.y < B.y || (A.y == B.y && A.x < B.x);
}

void solve() {
    sort(p, p + n, cmpXY); 
    for (int i = 2; i < n; i++) {
        if ((p[0] - p[1]) * (p[i] - p[1]) != 0) {
            printf("%d %d %d\n", p[0].id, p[1].id, p[i].id);
            return;
        }
    }

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