#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <unordered_set>
#include <unordered_map>


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
#define dbg(x) { cerr << #x << " = " << x << endl; }
const int N = 1e5 + 10;
const int INF = 1e9;

int a[N];
int n, t;

void read() {
    scanf("%d%d", &n, &t); t--;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int pos = 0;
    for (; pos < t; ) {
        pos += a[pos];
        if (pos == t) {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
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