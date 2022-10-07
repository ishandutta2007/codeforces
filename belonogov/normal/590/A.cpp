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
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;

int n;
int a[N];
int b[N];
bool hard[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void solve() {
    hard[0] = 1;
    hard[n - 1] = 1;
    for (int i = 1; i < n - 1; i++) {
        if (a[i] == a[i + 1]) 
            hard[i] = 1;
        if (a[i] == a[i - 1])
            hard[i] = 1;
    }
     
    memset(b, -1, sizeof(b));
    for (int i = 0; i < n; i++) {
        if (hard[i])
            b[i] = a[i];
    }
    int mx = 0;
    for (int i = 0; i < n; ) {
        for (; i < n && hard[i]; i++);
        int j = i;
        if (i == n) break;
        for (; i < n && !hard[i]; i++);
        assert(i < n);
        if (a[j - 1] == a[i]) {
            for (int t = j; t < i; t++)
                b[t] = a[i];
            mx = max(mx, (i - j + 1) / 2);
        }
        else {
            int mid = (j + i) / 2; 
            for (int t = j; t < mid; t++)
                b[t] = a[j - 1];
            for (int t = mid; t < i; t++)
                b[t] = a[i];
            mx = max(mx, (i - j) / 2);
        }

    }

    printf("%d\n", mx);
    for (int i = 0; i < n; i++)
        printf("%d ", b[i]);
    puts("");

}

void stress() {

}


int main(){
#ifdef MY_DEBUG
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