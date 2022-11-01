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
#define count ololo

int n;
vector <pair <int, int> > inp;
vector <vector < pair <int, int> > > g;
vector <int> w;
vector <int> count;
int timer = 0;
vector <int> tin;


void dfs(int v, int p = -1) {
    ++timer;
    tin[v] = timer;

    count[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i].first;
        if (to == p) {
            continue;
        }
        dfs(to, v);

        count[v] += count[to];
    }

}

void solve() {
    cin >> n;
    g.resize(n);
    count.resize(n);
    inp.resize(n - 1);
    tin.resize(n);
    w.resize(n - 1);

    for (int i = 0; i < n - 1; ++i) {
        int x, y, z;
        cin >> inp[i].first >> inp[i].second;
        --inp[i].first;
        --inp[i].second;

        cin >> z;
        g[inp[i].first].push_back(mp(inp[i].second, z));
        swap(inp[i].first, inp[i].second);
        w[i] = z;
        g[inp[i].first].push_back(mp(inp[i].second, z));
    }
    dfs(0);


    ld sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (tin[inp[i].first] < tin[inp[i].second])
            swap(inp[i].first, inp[i].second);

        sum += ld(w[i]) * ld(count[inp[i].first]) * ld(n - count[inp[i].first]);
    }
    

    int q;
    cin >> q;
    for (int tt = 0; tt < q; ++tt) {
        int id, we;
        cin >> id >> we;
        --id;
        sum -= ld(w[id] - we) * ld(count[inp[id].first]) * ld(n - count[inp[id].first]);
        w[id] = we;
        cout << sum * 6.0 / (ld(n) * ld(n - 1)) << "\n";
    }
}