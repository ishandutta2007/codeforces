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
const int N = 1e6 + 10;
const int INF = 1.01e9;
typedef vector<int> vi;


int answer[N];

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
    freopen("out", "w", stdout);
#endif
    int n, x;
    scanf("%d%d", &n, &x);
    assert(n <= 1e5);
    assert(x <= 1e5);
    mt19937 rnd(1919);
    int F = 1e6;
    int tmr = 0;
    //cerr << rnd() << endl;
    int it = 0;
    if (n == 2 && x == 0) {
        puts("NO");
        return 0;
    }
    while (true) {
        it++;
        assert(it < 10);
        tmr++;
        ll curXor = x;
        int size = 0;
        for (; size < n - 1;) {
            ll y = rnd() % F + 1;
            if (answer[y] != tmr) {
                answer[y] = tmr;
                size++;
                curXor ^= y;
            }
        }
        if (answer[curXor] != tmr && curXor <= F) {
            answer[curXor] = tmr;
            size++;
            break;
        }
        else {
            db("FAIL");
        }
    }

    puts("YES");
    ll Q = 0;
    for (int i = 0; i <= F; i++) {
        if (answer[i] == tmr) {
            printf("%d ", i);
            Q ^= i;
        }
    }
    puts("");

    db(Q);

    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}