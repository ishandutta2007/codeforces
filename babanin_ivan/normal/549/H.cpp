#pragma comment (linker, "/STACK:128000000")
#include <iostream> 
#include <cstdio> 
#include <fstream>
#include <functional>
#include <set> 
#include <map> 
#include <vector> 
#include <queue> 
#include <stack> 
#include <cmath> 
#include <algorithm> 
#include <cstring> 
#include <bitset> 
#include <ctime> 
#include <sstream>
#include <stack> 
#include <cassert> 
#include <list> 
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long li;
typedef long long i64;
typedef pair <int, int> pi;
typedef vector <int> vi;
typedef double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

//int timer = 0;
#define FILENAME ""

int main() {
    string s = FILENAME;
#ifdef YA
    //assert(!s.empty());
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //cerr<<FILENAME<<endl;
    //assert (s != "change me please");
    clock_t start = clock();
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout); 
    cin.tie(0);
#endif
    cout.sync_with_stdio(0);
    cout.precision(12);
    cout << fixed;
    int t = 1;
    
    //cin >> t;
    for (int i = 1; i <= t; ++i) {
        //++timer;
        //cout << "Case #" << i << ": ";
        solve();
    }
#ifdef YA
    cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
    return 0;
}

ld a[2][2];

const ld eps = 1e-10;

bool check(ld x) {
    ld b[2][2];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            b[i][j] = a[i][j];
        }
    }
    
    for (int u = 0; u < 2; ++u) {
        for (int z = -1; z <= 1; z += 2) {
            ld l1 = - b[0][0] + x * z;
            if (fabs(l1) < 1e-07 && fabs(b[1][0]) < x + eps) {
                return true;
            }
            if (fabs(l1) > eps) {
                ld bk[2];
                bk[0] = (-x - b[1][0]) / l1;
                bk[1] = (x - b[1][0]) / l1;
                if (bk[0] > bk[1]) {
                    swap(bk[0], bk[1]);
                }

                ld bl2[2];
                bl2[0] = -x - b[0][1];
                bl2[1] = x - b[0][1];
                if (bl2[0] > bl2[1]) {
                    swap(bl2[0], bl2[1]);
                }

                ld bl2k[2];
                bl2k[0] = -x - b[1][1];
                bl2k[1] = x - b[1][1];
                if (bl2k[0] > bl2k[1]) {
                    swap(bl2k[0], bl2k[1]);
                }

                ld bords[2];
                bords[0] = bords[1] = bk[0] * bl2[0];

                for (int i = 0; i < 2; ++i) {
                    for (int j = 0; j < 2; ++j) {
                        bords[0] = min(bords[0], bk[i] * bl2[j]);
                        bords[1] = max(bords[1], bk[i] * bl2[j]);
                    }
                }

                if (max(bords[0], bl2k[0])  < min(bords[1], bl2k[1]) + eps) {
                    return true;
                }
            }
        }

        swap(b[0][0], b[1][0]);
        swap(b[0][1], b[1][1]);
    }

    return false;
}

void solve() {
    
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> a[i][j];
        }
    }

    ld ans = 1000000000;

    bool f = check(0.2);

    for (int u = 0; u < 2; ++u) {
        ld l = 0;
        ld r = 1000000000;

        for (int it = 0; it < 20000; ++it) {
            ld m = (l + r) / 2;

            if (check(m)){
                r = m;
            }
            else {
                l = m;
            }
        }

        swap(a[0][1], a[1][0]);
        bool f = check(0.2);
        ans = min(ans, r);
    }
    
    cout << ans << endl;
}