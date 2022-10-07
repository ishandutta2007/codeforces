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
    int h;
    scanf("%d", &h);
    vector<int> a(h + 1);
    int n = 0;
    for (int i = 0; i <= h; i++) {
        n += a[i];
        scanf("%d", &a[i]);
    }
    assert(a[0] == 1);

    bool good = 1;  
    for (int i = 0; i < h; i++) {
        if (a[i] >= 2 && a[i + 1] >= 2) {
            good = 0;
        }
    }
    if (good) {
        puts("perfect");
    }
    else {
        puts("ambiguous");
        {
            vector<int> prev;
            prev.pb(-1);
            int cur = 0;
            for (int i = 0; i <= h; i++) {
                vector<int> level;
                for (int j = 0; j < a[i]; j++) {
                    cout << prev[0] + 1 << " ";
                    level.pb(cur++);
                }
                prev = level;
            }
        }
        cout << endl;
        {
            vector<int> prev;
            prev.pb(-1);
            int cur = 0;
            for (int i = 0; i <= h; i++) {
                vector<int> level;
                for (int j = 0; j < a[i]; j++) {
                    cout << prev[j % prev.size()] + 1 << " ";
                    level.pb(cur++);
                }
                prev = level;
            }
        }
        cout << endl;
    }

    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}