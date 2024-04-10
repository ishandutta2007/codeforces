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

int n;

void solve() {  
    cin >> n;
    vector <int> a;
    int sum1, sum2;
    sum1 = sum2 = 0;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        vector <int> b;
        b.resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> b[j];
        }
        if (m & 1) {
            for (int j = 0; j < m / 2; ++j) {
                sum1 += b[j];
            }
            for (int j = 0; j < m / 2; ++j) {
                sum2 += b[m - 1 - j];
            }
            a.push_back(b[m / 2]);
        }
        else {
            for (int j = 0; j < m / 2; ++j) {
                sum1 += b[j];
            }
            for (int j = 0; j < m / 2; ++j) {
                sum2 += b[m - 1 - j];
            }
        }
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for (int i = 0; i < a.size(); ) {
        sum1 += a[i];
        if (i + 1 < a.size()) {
            sum2 += a[i + 1];
        }
        i += 2;
    }
    cout << sum1 << " " << sum2 << endl;
}