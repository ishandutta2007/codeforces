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



int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    vector<int> c(n);
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &c[i], &d[i]);
    }
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int x = c[i];
            int y = d[i];
            int w = c[j];
            int z = d[j];
            forn(t1, 2) {
                forn(t2, 2) {
                    bool ok = 1;
                    ok &= x <= a && y <= b;
                    ok &= z <= a && w <= b;
                    ok &= !(a - z < x && b - w < y);
                    if (ok) {
                        answer = max(answer, x * y + w * z);
                    }
                    swap(w, z);
                }
                swap(x, y);
            }
        }
    }


    cout << answer << endl;
    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}