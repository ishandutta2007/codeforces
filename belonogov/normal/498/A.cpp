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

#define equal equalll
#define less lesss
#define x1 x111
#define y1 y111
const int N = 10000;
const int INF = 1e9 + 19;

int x1, y1;
int x2, y2;

int sign(long long x) {
    if (x > 0) return 1;
    return -1;
}

void read() {
    scanf("%d%d", &x1, &y1);
    scanf("%d%d", &x2, &y2);
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        long long r1 = a * 1ll * x1 + b * 1ll * y1 + c;
        long long r2 = a * 1ll * x2 + b * 1ll * y2 + c;
        assert(r1 != 0 && r2 != 0);
        cnt += sign(r1) * sign(r2) < 0;
    }
    cout << cnt << endl;
}

void solve() {

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