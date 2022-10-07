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
const int N = 2e5 + 10;
const long long INF = 1e18 + 19;
const int T = 1e5;
const int G = 100;

int n;
int a[N];
int p[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

double calc(double x) {
    double mx = -INF;
    double mn = INF;
    for (int i = 0; i <= n; i++) {
        double val = p[i] - x * i;
        mx = max(mx, val);
        mn = min(mn, val);
    }
    return mx - mn;
}

void solve() {
    for (int i = 0; i < n; i++)
        p[i + 1] = p[i] + a[i];
    double l = -T; 
    double r = T;
    for (int tt = 0; tt < G; tt++) {
        double m1 = (l + l + r) / 3;
        double m2 = (l + r + r) / 3;
        double r1 = calc(m1);
        double r2 = calc(m2);
        if (r1 > r2)
            l = m1;
        else
            r = m2;
    }
    //db(l);
    printf("%.17f\n", calc(l));
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