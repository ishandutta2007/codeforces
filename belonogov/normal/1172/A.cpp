#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define F first
#define S second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define pw(x) (1LL<<(x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl

using namespace std;

typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;


int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK".in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
         scanf("%d", &b[i]);
    }
    int r2 = INF;
    for (int i = 0; i < n; i++) {
        if (b[i] == 1) {
            bool ok = 1;
            for (int j = i; j < n; j++) {
                ok &= b[j] == 1 + (j - i);
            }
            if (ok) {
                bool fail = 0;
                for (int j = 0; j < i; j++) {
                    if (b[j] != 0)  {
                        int val = j + (n - i) + 1;
                        fail |= b[j] <= val;
                    }
                }
                if (!fail) {
                    r2 = i;
                }
            }
            break;
        }
    }


    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] != 0) {
            mx = max(mx, i + 1 - (b[i] - 1));
        }
    }
    int r1 = mx + n;
//    db2(r1, r2);

    cout << min(r1, r2) << endl;
    return 0;
}