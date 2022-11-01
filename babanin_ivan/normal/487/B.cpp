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

int n, s, l;
vector <int> a;

struct eve {
    int pos;
    bool f;
    eve(int pos, bool f):pos(pos),f(f) {}
    bool operator < (const eve& oth) const {
        return f < oth.f;
    }

    eve(){}
};

void solve() {
    cin >> n >> s >> l;
    a.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    set <pair <int, int> > b;
    //set < pair <int, int> , greater <pair <int, int> > > c;


    int j = 0;

    vector <int> dp1(n);

    for (int i = 0; i < n; ++i) {
        
        if (i > 0)
            b.erase(mp(a[i - 1], i - 1));
        

        while ((j < n) && (b.empty() || (*(--b.end())).first - a[j] <= s && a[j] - (*b.begin()).first <= s)) {
            b.insert(mp(a[j], j));
            ++j;
        }

        dp1[i] = j;
    }

    int inf = 1000000;

    vector <int> dp2(n + 1, inf);

    vector < vector < eve > > events(n + 1);
    
    for (int i = 0; i < n; ++i) {
        if (i + l <= dp1[i]) {
            events[i + l - 1].push_back(eve(i, true));
            events[min(n, dp1[i])].push_back(eve(i, false));
        }
    }
    
    set <pair <int, int> > upd;
    dp2[0] = 0;

    for (int i = 0; i < n; ++i) {
        sort(events[i].begin(), events[i].end());
        for (int j = 0; j < events[i].size(); ++j) {
            if (events[i][j].f) {
                upd.insert(mp(dp2[events[i][j].pos] + 1, events[i][j].pos));
            }
            else {
                upd.erase(mp(dp2[events[i][j].pos] + 1, events[i][j].pos));
            }
        }
        if (!upd.empty()) {
            dp2[i + 1] = min(dp2[i + 1], (*upd.begin()).first);
        }
    }

    if (dp2[n] == inf) {
        cout << -1 << "\n";
    }
    else cout << dp2[n] << "\n";
}