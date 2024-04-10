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

int n, m;
int a[5000];
int b[5000];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    
    int point = 0;
    int need = n;

    for (int i = 0; i < n; ++i) {
        while (point < m && b[point] < a[i]) {
            ++point;
        }
        if (point == m) {
            break;
        }
        else {
            --need;
            ++point;
        }
    }

    cout << need << endl;
}