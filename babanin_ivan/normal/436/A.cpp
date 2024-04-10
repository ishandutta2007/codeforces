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

int n, x;

struct can {
    int h, m;
    can(int h, int m):h(h),m(m){}
    bool operator <(const can& oth) const{
        return mp(h, m) < mp(oth.h, oth.m);
    }
};

vector <can> a[2];

void solve() {
    cin >> n >> x;
    for (int i = 0; i< n; ++i) {
        int t, h, m;
        cin >> t >> h >> m;
        a[t].push_back(can(h, m));
    }
    for (int i = 0; i < 2; ++i)
        sort(a[i].begin(), a[i].end());
    int ans = 0;
    for (int st = 0; st < 2; ++st) {
        int ans2 = 0;
        int curx = x;
        int cur = st;
        int uk[2];
        uk[0] = uk[1] = 0;
        
        set <pair <int, int> > eat[2];

        while (true) {
            while (uk[cur] < a[cur].size() && a[cur][uk[cur]].h <= curx) {
                eat[cur].insert(mp(a[cur][uk[cur]].m, uk[cur]));
                ++uk[cur];
            }
            if (eat[cur].empty())
                break;
            ++ans2;
            curx += (*eat[cur].rbegin()).first;
            eat[cur].erase(*eat[cur].rbegin());
            cur = !cur;
        }
        ans = max(ans, ans2);
    }
    cout << ans << endl;
}