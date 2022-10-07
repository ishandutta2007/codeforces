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
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
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



int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n = 4;
    vector<int> a(n);
    for (int i = 0; i < 4; i++) {
        scanf("%d", &a[i]);
    }
    for (int it = 0;; it++) {
        db(it);
        for (auto x: a) {
            cerr << x << " ";
        }
        cerr << endl;
        bool ok = 1;
        for (auto x: a) {
            ok &= x == 1;
        }
        if (ok) break;

        int mx = 0;
        for (auto x: a) mx = max(mx, x);
        if (mx >= 4) {
            bool done = 0;
            for (int i = 0; i < 4; i++) {
                if (a[i] % 2 == 0 && a[(i + 1) % 4] % 2 == 0) {
                    done = 1;
                    a[i] /= 2;
                    a[(i + 1) % 4] /= 2;
                    cout << "/" << i + 1 << endl;
                    break;
                }
            }
            if (done) continue;
        }

        int type = rand() % 2;
        if (type == 1) {
            int x = rand() % 4;
            cout << "+" << x + 1 << endl;
            a[x]++;
            a[(x + 1) % 4]++;
        }
        else {
            for (int tt = 0; tt < 3; tt++) {
                int p = rand() % 4;
                if (a[p] % 2 == 0 && a[(p + 1) % 4] % 2 == 0) {
                    a[p] /= 2;
                    a[(p + 1) % 4] /= 2;
                    cout << "/" << p + 1 << endl;
                    break;
                }
            }
        }
    } 



    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}