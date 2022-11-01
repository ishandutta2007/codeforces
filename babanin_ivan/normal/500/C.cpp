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

int n, m;
vector <int> w;
vector <int> b;
vector <int> used;
int ans = 0;
vector <int> a;

void solve() {
    cin >> n >> m;
    w.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    b.resize(m);
    int sum = 0;
    used.resize(n);

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        --b[i];
        if (!used[b[i]]) {
            ans += sum;
            a.push_back(b[i]);
            used[b[i]] = 1;
            sum += w[b[i]];
        }
        else {
            for (int j = a.size() - 1; j >= 0; --j) {
                if (a[j] == b[i]) {
                    a.erase(a.begin() + j);
                    a.push_back(b[i]);
                    break;
                }
                else {
                    ans += w[a[j]];
                }
            }
        }
    }

    
    cout << ans << endl;
}