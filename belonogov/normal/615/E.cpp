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
const long long INF = 2e18 + 19;
const int INF9 = 1e9 + 10;

long long n;

struct pnt {
    long long x, y;
    pnt () { }
    pnt (long long x, long long y): x(x), y(y) { }
    pnt operator + (pnt A) {
        return pnt(x + A.x, y + A.y);
    }
    pnt operator - (pnt A) {
        return pnt(x - A.x, y - A.y);
    }
    pnt operator * (long long k) {
        return pnt(x * k, y * k);
    }
};


long long calc(long long x) {
    if (x * 1.0 * x * 3 > 2e18) return INF;
    long long cnt;
    x--;
    cnt = 1 + x * (x + 1) / 2 * 6;
    return cnt;
}


void read() {
    long long x;
    cin >> x;
    if (x == 0) {
        puts("0 0");
        return;
    }
    long long l = 0;
    long long r = INF9; 
    while (r - l > 1) {
        if (calc((l + r) / 2) > x)
            r = (l + r) / 2;
        else
            l = (l + r) / 2;
    }

    x -= calc(l);   
    pnt O(l * 2, 0);
    x++;
    assert(x > 0);
    vector < pnt > dir;
    dir.pb(pnt(-1, 2));
    dir.pb(pnt(-2, 0));
    dir.pb(pnt(-1, -2));
    dir.pb(pnt(1, -2));
    dir.pb(pnt(2, 0));
    dir.pb(pnt(1, 2));

    for (int i = 0; i < 6; i++) {
        if (x <= l) {
            O = O + dir[i] * x;
            break;
        }
        else {
            x -= l;
            O = O + dir[i] * l;
        }

    }

    cout << O.x << " " << O.y << endl;     





}

void solve() {

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