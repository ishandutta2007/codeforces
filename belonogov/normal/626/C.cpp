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


int n, m;
void read() {
    scanf("%d%d", &n, &m);

}

bool check(int h) {
    int d3 = h / 3; 
    int d2 = h / 2;
    int d6 = h / 6;
    d3 -= d6;
    d2 -= d6;
    int nn = n;
    int mm = m;
    nn = max(0, nn - d2);
    mm = max(0, mm - d3);
    
    return nn + mm <= d6;
}

void solve() {
    int l = -1;
    int r = INF;
    while (r - l > 1) {
        if (check((l + r) / 2))
            r = (l + r) / 2;
        else
            l = (l + r) / 2;
    }
    printf("%d\n", r);
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