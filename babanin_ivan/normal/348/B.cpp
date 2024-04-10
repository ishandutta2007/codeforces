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
vector <int> a;
vector <vector <int> > g;

li min(li x, li y) {
    if (x < y)
        return x;
    return y;
}

void print(li x) {
    li sum = 0;
    for (int i = 0; i < a.size(); ++i) {
        sum += a[i];
    }
    cout << sum - x << endl;
    exit(0);
}

li gcd(li x, li y) {
    if (x % y == 0) {
        return y;
    }
    return gcd(y, x % y);
}

pair <li, li> get(int v, int p = -1) {
    vector < pair <li, li> > go;

    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p) {
            continue;
        }
        go.push_back(get(to, v));
    }
    if (go.size() == 0) {
        pair <li, li> ret = make_pair(a[v], 1);
        if (ret.first == 0) {
            print(0);
        }
        return ret;
    }
    if (go.size() == 1) {
        return go[0];
    }

    pair <li, li> res;

    li T = 1;
    for (int i = 1; i < go.size(); ++i) {
        li tmp = go[i].second / gcd(go[0].second, go[i].second);
        li tmp2 = gcd(T, tmp);
        T = (T * tmp) / tmp2;
    }
    
    res.first = (go[0].first / go[0].second) / T;
    for (int i = 1; i < go.size(); ++i) {
        res.first = min(res.first, go[i].first / (T * go[0].second));
    }

    
    res.second = 1;
    for (int i = 0; i < go.size(); ++i) {
        li tmp = gcd(res.second, go[i].second);
        res.second = (res.second * go[i].second) / tmp;
    }
    res.second *= go.size();
    res.first *= T;
    res.first *= go[0].second * go.size();
    if (res.first == 0)
        print(0);
    return res;
}

void solve() {
    cin >> n;
    a.resize(n);
    g.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    pair <li, li> res = get(0);
    print(res.first);
}