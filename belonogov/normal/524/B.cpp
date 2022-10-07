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

#define equal equalll
#define less lesss
const int N = 1e3 + 10;
const int INF = 1e9;

int n;
int a[N];
int b[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &a[i], &b[i]);
}

void solve() {
    int mx = 0;
    int mn = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i])
            swap(a[i], b[i]);
        mx = max(mx, b[i]);
        mn = max(mn, a[i]);

    }
    int ans = INF;
    //cerr << "mn mx: " << mn << " " << mx << endl;
    for (int h = mn; h <= mx; h++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (h >= b[i])
                sum += a[i];
            else
                sum += b[i];
        }
        ans = min(ans, sum * h);
    }
    printf("%d\n", ans);
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
        while (true) {
            read();
            solve();
            printAns();
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}