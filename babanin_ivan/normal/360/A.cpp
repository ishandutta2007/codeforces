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
vector <int> a;
vector <bool> b;
vector <int> aa;
vector <pair <pair <int, int> , pair <int, int> > > c;
vector <int> res;

void printerr() {
    cout << "NO\n";
    exit(0);
}

void solve() {
    cin >> n >> m;
    a.resize(n);
    aa.resize(n);
    b.resize(n, 0);
    c.resize(m);
    res.resize(n);

    for (int i = 0; i < m; ++i) {
        int l, r, t, d;
        cin >> t;
        cin >> l >> r;
        cin >> d;
        --l;
        --r;
        c[i] = mp(mp(t, d), mp(l, r));
        
        if (t == 2) {
            int cur = d;
            bool f = false;
            for (int j = l; j <= r; ++j) {
                int t = d - a[j];
                if (b[j]) {
                    if (aa[j] >= t)
                        f = true;
                }
                else {
                    f = true;
                }
                if (!b[j]) {
                    aa[j] = t;
                    b[j] = true;
                }
                aa[j] = min(aa[j], t);
                
            }
            if (!f)
                printerr();
            
        }
        else {
            for (int j = l; j <= r; ++j)
                a[j] += d;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (b[i])
            res[i] = aa[i];
        else res[i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int l, r, t, d;
        t = c[i].first.first;
        d = c[i].first.second;
        l = c[i].second.first;
        r = c[i].second.second;
        if (t == 1) {
            for (int j = l; j <= r; ++j)
                res[j] += d;
        }
        else {
            int mx = res[l];
            for (int j = l; j <= r; ++j)
                mx = max(mx, res[j]);
            if (mx != d)
                printerr();
        }
    }
    for (int i = 0; i < n; ++i)
        if (b[i])
            res[i] = aa[i];
        else res[i] = 0;
    cout << "YES\n";
    for (int i = 0; i < n; ++i)
        cout << res[i] << " ";
}