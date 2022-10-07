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
const int N = -1;
const long long INF = 1e9 + 19;

int n;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        long long l, r;
        scanf("%lld%lld", &l, &r);
        if (l == r) {
            printf("%lld\n", l);
            continue;
        }
        int pos = 63;
        for (; ((r >> pos) & 1) == ((l >> pos) & 1); pos--);
        long long res = l | ((1ll << pos) - 1);
        int cntRes = __builtin_popcountll(res);
        int cntR = __builtin_popcountll(r);
        //db2(cntRes, cntR);
        assert(cntRes + 1 >= cntR);
        if (cntR > cntRes)
            res = r;
        printf("%lld\n", res);
    }

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