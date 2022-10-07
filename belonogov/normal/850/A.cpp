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
const int INF = 1.01e9;
typedef vector<int> vi;
const int K = 5;

struct pt {
    int a[K];
    int operator % (pt A) {
        int sum = 0;
        forn(i, K) {
            sum += a[i] * A.a[i];
        }
        return sum;
    }
    pt operator - (pt A) {
        pt res;
        forn(i, K) {
            res.a[i] = a[i] - A.a[i];
        }
        return res;
    }
    void read() {
        forn(i, K) {
            scanf("%d", &a[i]);
        }
    }
};

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    vector<pt> p(n);
    forn(i, n) {
        p[i].read();
    }
    if (n > 100) {
        puts("0");
        return 0;
    }
    vector<int> answer;
    forn(i, n) {
        bool bad = 0;
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (k == i || k == j) continue;
                bad |= (p[j] - p[i]) % (p[k] - p[i]) > 0;
            }
        }
        if (!bad) {
            answer.pb(i);
        }
    }
    printf("%d\n", sz(answer));
    for (auto x: answer) {
        printf("%d ", x + 1);
    }
    puts("");
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}