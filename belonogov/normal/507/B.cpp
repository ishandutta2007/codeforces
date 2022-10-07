#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define pr(x) { cerr << #x << " = " << x << endl; }
const int N = -1;
const int INF = 1e9;
const double eps = 1e-6;


void read() {
    long long x1, x2, y1, y2, r;
    scanf("%lld%lld%lld%lld%lld", &r, &x1, &y1, &x2, &y2);
    double l = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    r *= 2;
    long long cnt = l / r;
    if (r * cnt + eps < l)
        cnt++;
    printf("%lld\n", cnt);
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