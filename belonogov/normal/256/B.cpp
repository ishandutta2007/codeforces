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

long long n, c, x, y;

void read() {
    scanf("%lld%lld%lld%lld", &n, &x, &y, &c); x--; y--; 
}

long long toLine(long long x) {
    if (x < 0) return 0;
    return x * x;
}

long long toSquare(long long x) {
    if (x < 0)
       return 0; 
    return x * (x + 1) / 2;
}


long long calc(long long t) {
    long long res = t * t + (t + 1) * (t + 1);
    
    res -= toLine(t - x);
    res -= toLine(t - y);
    res -= toLine(t - (n - 1 - x));
    res -= toLine(t - (n - 1 - y));

    res += toSquare(t - x - y - 1);
    res += toSquare(t - (n - 1 - x) - y - 1);
    res += toSquare(t - (n - 1 - x) - (n - 1 - y) - 1);
    res += toSquare(t - x - (n - 1 - y) - 1);
    return res;
}

void solve() {
    //db(calc(0));
    //db(calc(1));
    //db(calc(2));
    //db(calc(3));
    //db(calc(4));
    //db(calc(5));
    //db(calc(6));
    //db(calc(7));


    long long l = -1;
    long long r = 2 * n + 1;
    while (r - l > 1) {
        if (calc((l + r) / 2) >= c)
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