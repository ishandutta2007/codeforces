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

const int dx[2] = {-1, 0};
const int dy[2] = {0, -1};

const int mod = 1000000007;

vector <vector <char> > a;
vector <vector <int> > f[2];
int n, m;

li get(pair <int, int> start, pair <int, int> end) {
    
    int id = start.first;
    if (f[id].size() == n) {
        return f[id][end.first][end.second];
    }
    f[id].assign(n, vector <int> (m));
    f[id][start.first][start.second] = (a[start.first][start.second] != '#');
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '#') {
                continue;
            }
    
            if (j - 1 >= 0) {
                f[id][i][j] += f[id][i][j - 1];
            }
            if (i - 1 >= 0) {
                f[id][i][j] += f[id][i - 1][j];
            }

            if (f[id][i][j] >= mod) {
                f[id][i][j] -= mod;
            }
        }
    }
    return f[id][end.first][end.second];
}

void solve() {
    cin >> n >> m;
    a.resize(n, vector <char> (m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    li ans = get(make_pair(0, 1), make_pair(n - 2, m - 1)) * get(make_pair(1, 0), make_pair(n - 1, m - 2)) - get(make_pair(0, 1), make_pair(n - 1, m - 2)) * get(make_pair(1, 0), make_pair(n - 2, m - 1));
    if (ans < 0) {
        ans = mod - ((-ans) % mod);
    }
    cout << ans % mod << "\n";
}