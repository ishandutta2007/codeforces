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
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = -1;
const int INF = 1e9 + 19;
const int MOD = 1e9 + 7;

long long binPow(long long a, long long b) {
    long long res = 1;
    for (; b > 0; b /= 2) {
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
    }
    return res;
}


void read() {
    int n;
    scanf("%d", &n);
    n = n + 1;
    long long fact2n = 1;
    long long factn = 1;
    for (int i = 1; i <= n * 2; i++)
         fact2n = (fact2n * i) % MOD;
    for (int i = 1; i <= n; i++)
         factn = (factn * i) % MOD;
    long long rev = binPow(factn, MOD - 2);
    long long answer = fact2n * rev % MOD * rev;
    answer = (answer + MOD - 1) % MOD;
    cout << answer << endl;
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