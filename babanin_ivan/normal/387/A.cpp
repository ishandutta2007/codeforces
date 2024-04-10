#include <iostream> 
#include <cstdio> 
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
//#include <unordered_set> 
using namespace std;
typedef long long int64;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define mp make_pair 
#define pb push_back 
#define all(s) s.begin(), s.end() 
void solve();

#define NAME "changemeplease"
int main() {
#ifdef YA 
    cerr << NAME << endl;
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
    while (t--)
        solve();

#ifdef YA 
    cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif 
    return 0;
}

void solve() {
    char c[2][5];
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 5; ++j) {
            cin >> c[i][j];
        }
    int t1, t2;
    t1 = (c[0][0] - '0') * 10 * 60 + (c[0][1] - '0') * 60 + (c[0][3] - '0') * 10 + (c[0][4] - '0');
    t2 = (c[1][0] - '0') * 10 * 60 + (c[1][1] - '0') * 60 + (c[1][3] - '0') * 10 + (c[1][4] - '0');
    t1 -= t2;
    if (t1 < 0) {
        t1 += 24 * 60;
    }
    int a1, a2;
    a2 = t1 % 60;
    a1 = t1 / 60;
    cout << a1 / 10 << "" << a1 % 10 << ":" << a2 / 10 << a2 % 10 << endl;
}