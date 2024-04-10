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

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)

#define equal equalll
#define less lesss
#define left lefttt
const int N = -1;
const int INF = 1e9;
const int T = 6e6;


int a, b, n;
int left, t, m; 

void read() {
    scanf("%d%d%d", &a, &b, &n);
}

bool check(int pos) {
    int len = pos + 1 - left;
    long long sum = (a * 1ll * len);
    sum += left * 1ll * b * len;
    sum += (len * 1ll * (len - 1)) / 2 * b;
    if (pos * 1ll * b + a <= t && sum <= t * 1ll * m)
       return 1; 
    return 0;
}

void solve() {
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &left, &t, &m); left--;
        int l = left - 1;
        int r = T;
        while (r - l > 1) {
            if (check((l + r) / 2)) 
                l = (l + r) / 2;
            else
                r = (l + r) / 2;
        }
        if (r == left) {
            printf("-1\n");
        }
        else
            printf("%d\n", r);
    }

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