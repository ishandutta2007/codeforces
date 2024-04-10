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

int n, m, k;

char c[2100][2100];

const int dx[4] = {0,0,-1,1};
const int dy[4] = {1,-1,0,0};
const char let[4] = {'L','R','D','U'};

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> c[i][j];
        }
    }
    int ans = -1;
    for (int st = 0; st < m; ++st) {
        int ans2 = 0;
        for (int i = 0; i < n; ++i) {
            for (int t = 0; t < 4; ++t) {
                pair <int, int> to = mp(i + dx[t] * i, st + dy[t] * i);
                if (to.first >= 0 && to.second >= 0 && to.first < n && to.second < m)
                    ans2 += (c[to.first][to.second] == let[t]);
            }
        }
        cout << ans2 << " ";
        //if (ans == -1 || ans2 < ans)
        //  ans = ans2;
    }
    //cout << ans << endl;
}