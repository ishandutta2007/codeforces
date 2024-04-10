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

vector <int> a;
vector <int> used;

void go(int v) {
    used[v] = 1;
    if (v == a.size())
        return;
    int to = v + a[v];
    if (!used[to]) {
        go(to);
    }
}

void solve() {
    int n;
    cin >> n;
    used.resize(n, 0);
    int t;
    cin >> t;
    --t;

    a.resize(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i];
    }

    go(0);
    if (used[t]) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}