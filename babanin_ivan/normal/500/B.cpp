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
vector <vector <int> > a;
vector <int> p;

vector <int> used;
int col;
vector <vector <int> > groups;

void dfs(int v) {
    groups[used[v]].push_back(p[v]);

    for (int i = 0; i < n; ++i) {
        if (a[v][i] && used[i] == 0) {
            used[i] = used[v];
            //groups[used[i]].push_back(p[i]);
            dfs(i);
        }
    }
}

void solve() {
    
    cin >> n;
    groups.resize(n + 2);
    p.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    a.resize(n);
    for (int i = 0; i < n; ++i) {
        a[i].resize(n);
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            if (c == '1') {
                a[i][j] = 1;
            }
        }
    }

    int k = 0;
    used.resize(n);
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0) {
            ++k;
            used[i] = k;
            dfs(i);
        }
    }

    for (int i = 0; i <= k; ++i) {
        sort(groups[i].begin(), groups[i].end());
    }

    vector <int> point(n + 1);
    for (int i = 0; i < n; ++i) {
        cout << groups[used[i]][point[used[i]]] << " ";
        ++point[used[i]];
    }
}