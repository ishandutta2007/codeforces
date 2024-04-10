#pragma comment (linker, "/STACK:128000000")
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

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long li;
typedef long long i64;
typedef pair <int, int> pi;
typedef vector <int> vi;
typedef double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

//int timer = 0;
#define FILENAME ""

int main() {
    string s = FILENAME;
#ifdef YA
    //assert(!s.empty());
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //cerr<<FILENAME<<endl;
    //assert (s != "change me please");
    clock_t start = clock();
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout); 
    cin.tie(0);
#endif
    cout.sync_with_stdio(0);
    cout.precision(10);
    cout << fixed;
    int t = 1;
    //cin >> t;
    while (t--) {
        //++timer;
        solve();
    }
#ifdef YA
    cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
    return 0;
}

string s;
    int n, k;
string res;
vector <int> z;

void solve() {
    cin >> n >> k;
    
    cin >> s;
    res.assign(n, '0');
    
    int l = 0, r = 0;
    z.resize(n, 0);
    for (int i = 1; i < n; ++i) {
        if (i < r) {
            z[i] = min(z[i - l], r - i);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }

    z.push_back(0);

    vector <pair <int, int> > anses;

    for (int len = 1; len <= n; ++len) {
        bool f = true;
        
        if ((k - 1) * len >= n) {
            f = false;
            break;
        }

        for (int i = 1; i < k; ++i) {
            
            if (z[i * len] < len) {
                f = false;
                break;
            }
        }

        if (f) {
            anses.push_back(mp(k * len - 1, k * len - 1 + min(z[k * len], len)));
        }
    }

    sort(anses.begin(), anses.end());   
    int pointer = 0;

    for (int i = 0; i < n; ++i) {
        while (pointer < anses.size() && (i >= anses[pointer].first)) {
            if (i <= anses[pointer].second) {
                res[i] = '1';
                break;
            }
            ++pointer;
        }
    }

    cout << res << "\n";
}