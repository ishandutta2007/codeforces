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

void solve() {
    vector <int> a[2];
    for (int i = 0; i < 2; ++i) {
        a[i].resize(3);
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }

    vector <int> c(3);
    for (int i = 0; i < 3; ++i) {
        cin >> c[i];
    }

    int add[4];
    int ans = 1000000000;

    for (add[1] = 0; add[1] <= 300; ++add[1]) {
        for (add[2] = 0; add[2] <= 300; ++add[2]) {
            vector <int> b = a[0];
            b[1] += add[1];
            b[2] += add[2];
            if (b[1] <= a[1][2]) {
                continue;
            }

            int steps = (a[1][0] + b[1] - a[1][2] - 1) / (b[1] - a[1][2]);

            int newc = add[1] * c[1] + add[2] * c[2];

            if (b[2] >= a[1][1]) {
                ans = min(ans, newc);
            }
            else {
                int needhp = steps * (a[1][1] - b[2]) + 1;
                
                newc += c[0] * max(0, needhp - b[0]);

                ans = min(ans, newc);
            }
        }
    }

    cout << ans << endl;
}