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


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int N = -1;
const int INF = 1e9;

int n, m;
double ans;


double myPow(double x, int n) {
    double ans = 1;
    for (; n > 0; n /= 2) {
        if (n % 2 == 1)
            ans *= x;
        x *= x;
    }
    return ans;
}


void read() {
    if (scanf("%d%d", &m, &n) != 2) exit(0);
}

void solve() {
    ans = 0;
    double sum = 0;
    for (int i = m - 1; i >= 0; i--) {
        double tmp = myPow(i * 1.0 / m, n);
        tmp = 1 - tmp;
        tmp -= sum;
        ans += tmp * (i + 1);
        sum += tmp;
    }
}

void printAns() {
    printf("%.15lf\n", ans);
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
        }
    }
    else {
        stress();
    }

    return 0;
}