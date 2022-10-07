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
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define forn(i, n) for (int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = -1;
const ll INF = 1.01e9;
typedef vector<int> vi;


void ask(int pos, int& value, int& next) {
    cout << "? " << pos + 1 << endl;
    cin >> value >> next;
    next--;
}

void answer(int x) {
    cout << "! " << x << endl;
    exit(0);
}

int main(){
//#ifdef HOME assert(freopen("in", "r", stdin)); #endif
    int n, st, x;
    cin >> n >> st >> x;
    st--;
    int T = 1000;
    mt19937 rnd(1919);

    int bestValue = -INF, bestPos = st;
    for (int i = 0; i < T; i++) {
        int pos = rnd() % n;
        int value, next;
        ask(pos, value, next);
        if (value <= x && value > bestValue) {
            bestValue = value;
            bestPos = pos;
        }
    }

    int pos = bestPos; 
    for (int iter = 0;; iter++) {
        assert(iter < 1970 - T);
        int value, next;
        ask(pos, value, next);
        if (value >= x) {
            answer(value);
        }
        if (next == -2) {
            answer(-1);
        }
        pos = next;
    }

    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}