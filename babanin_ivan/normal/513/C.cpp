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
//#include <unordered_set> 
using namespace std;
typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define mp make_pair 
#define pb push_back
#define y1 botva
#define all(s) s.begin(), s.end() 
void solve();

#define NAME "changemeplease"
int main() {
#ifdef YA 
    //cerr << NAME << endl;
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout); 
    clock_t start = clock();
#else 
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
#endif 
    ios_base::sync_with_stdio(false);
    cout << fixed;
    cout.precision(10);
    int t = 1;
    //cin >> t;  
    for (int i = 1; i <= t; ++i) {
        //cout << "Case #" << i << ": ";
        solve();
    }
#ifdef YA 
    //cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif 
    return 0;
}

int n;
vector <pair <int, int> > a;

void solve() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    ld res = 0;

    for (int ans = 1; ans <= 10000; ++ans) {

        if (true) {
            bool f = true;
        }

        for (int mask = 0; mask < (1 << n); ++mask) {
            
            ld p = 1.0;

            int cou = 0;

            for (int i = 0; i < n; ++i) {
                if ((1 << i) & mask) {
                    ++cou;
                    if (ans > a[i].second) {
                        p = 0;
                    }
                    else {
                        if (ans >= a[i].first) {
                            p *= 1 - ld(ans - a[i].first) / (a[i].second - a[i].first + 1);
                        }
                    }
                }
                else {
                    if (ans - 1 < a[i].first) {
                        p = 0;
                    }
                    else {
                        if (ans - 1 <= a[i].second) {
                            p *= 1 - ld(a[i].second - (ans - 1)) / (a[i].second - a[i].first + 1);
                        }
                    }
                }
            }

            if (cou >= 2) {
                res += p;
            }
        }
    }

    cout << res << endl;
}