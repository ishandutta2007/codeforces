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

#define hash ololo

const int hash = 997;
int p[200000];
int n;
int h[200000];

int gethash(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

void solve() {
    string s;
    getline(cin, s);
    n = s.size();
    p[0] = 1;
    for (int i = 1; i <= n + 100; ++i) {
        p[i] = p[i - 1] * hash;
    }
    h[0] = 0;
    for (int i = 1; i <= n; ++i) {
        h[i] = h[i - 1] * hash + int(s[i - 1]);
    }
    
    vector <pair <int, int> > a;
    int pos = 0;
    while (pos < n) {
        pair <int, int> cur;
        cur.first = pos;
        ++pos;
        while (pos < n && s[pos] == '0') {
            ++pos;
        }
        cur.second = pos - 1;
        a.push_back(cur);
    }
    
    int ans = 1;
    int curend = a[0].second;


    for (int i = 1; i < a.size(); ++i) {
        if (curend + 1 > a[i].second - a[i].first + 1) {
            ++ans;
            curend = a[i].second;
            continue;
        }
        if (curend + 1 < a[i].second - a[i].first + 1) {
            ans = 1;
            curend = a[i].second;
            continue;
        }
        
        int len = 0;

        if (s[0] == s[a[i].first]) {
            int l = 1;
            int r = curend + 1;
            while (r - l > 2) {
                int m = (l + r) / 2;
                if (gethash(1, m) == gethash(a[i].first + 1, a[i].first + m)) {
                    l = m;
                }
                else {
                    r = m - 1;
                }
            }
            for (int j = r; j >= l; --j) {
                if (gethash(1, j) == gethash(a[i].first + 1, a[i].first + j)) {
                    len = j;
                    break;
                }
            }
        }
        if (len == curend + 1 || s[len] > s[a[i].first + len]) {
            ++ans;
        }
        else {
            ans = 1;
        }
        curend = a[i].second;
    }
    cout << ans << endl;
}