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

#define equal equalll
#define less lesss
const int N = -1;
const int INF = 1e9;
const int T = 100;


long double a, b, c, d;

pair < long double, long double > getS(long double a, long double b, long double s) {    
    vector < long double > x;    
    x.pb((a + s) * (b + s));
    x.pb((a + s) * (b - s));
    x.pb((a - s) * (b + s));
    x.pb((a - s) * (b - s));
    if (abs(a) < s || abs(b) < s)
        x.pb(0);
    sort(x.begin(), x.end());
    return mp(x[0], x.back());
}

bool check(long double s) {
    auto r1 = getS(a, d, s);
    auto r2 = getS(b, c, s);
    return max(r1.fr, r2.fr) < min(r1.sc, r2.sc);

}


void read() {
    cin >> a >> b >> c >> d;
    //if (a * d > b * c) {
        //swap(a, b);
        //swap(d, c);
    //}


    long double l = 0;
    long double r = 3e9;
    for (int i = 0; i < T; i++) {
        if (check((l + r) / 2))
            r = (l + r) / 2;
        else
            l = (l + r) / 2;
    }
    printf("%.17f\n", (double)l);
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