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
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;


int n;

void read() {
    scanf("%d", &n);
    int t = 200;
    int l = max(1, n - t);
    long long answer = 0;
    for (int i = l; i <= n; i++)
        for (int j = i; j <= n; j++)
            for (int k = j; k <= n; k++) {
                long long d = i * 1ll * j / __gcd(i, j);
                long long h = d * k / __gcd(d, 1ll * k);
                answer = max(answer, h);
            }
    //cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    printf("%lld\n", answer);
}

void solve() {

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