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
const int MOD = 1e9 + 7;

int n, k;
bool use[N];

void read() {
    cin >> n >> k;
}

void solve() {
    int mod = n;
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (!use[i]) {
            int v = i;
            for (; !use[v]; ) {
                use[v] = 1;
                v = v * 1ll * k % mod;
            }
            cnt++;
        }
    } 
    if (k == 1)
        cnt++;
    long long answer = 1;
    for (int i = 0; i < cnt; i++)
        answer = (answer * n) % MOD;

    cout << answer << endl;

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