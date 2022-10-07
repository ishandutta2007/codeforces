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
const int T = 60;

long long s, x;

void read() {
    cin >> s >> x;
}

void solve() {
    long long diff = s - x;
    if (diff < 0 || diff % 2 != 0) {
        puts("0");
        return;
    }
    bool flag = 1;
    int cnt = 0;
    for (int i = 1; i < T; i++) {
        if ((diff >> i) & 1) {
            int j = i - 1;
            flag &= (((x >> j) & 1) == 0);
            cnt++;
        }
    }
    if (!flag) {
        puts("0");
        return;
    }
    int all = __builtin_popcountll(x);
    if (cnt == 0) {
        printf("%lld", (1ll << all) - 2);
    }
    else {
        printf("%lld", (1ll << all));
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