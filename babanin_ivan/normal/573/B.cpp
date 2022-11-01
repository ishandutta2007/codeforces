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
    //freopen("output.txt", "w", stdout);
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
    for (int i = 1; i <= t; ++i) {
        //++timer;
        //cout << "Case #" << i << ": ";
        solve();
    }
#ifdef YA
    cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector <int> h(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }

    vector <int> used(n + 2);

    vector <pair <int, int> > q;

    for (int j = 0; j < h.size(); ++j) {
        q.push_back(mp(h[j], j));
    }

    sort(q.begin(), q.end());

    int sum = 0;


    int ans = 0;
    
    int p = 0;

    queue <int> w[2];
    
    int cur = 0;

    for (; ; ++ans) {

        
        for (; p < q.size(); ++p) {
            if (used[q[p].second]) {
                continue;
            }
            if (q[p].first == ans) {
                w[cur].push(q[p].second);
                used[q[p].second] = true;
                ++sum;
            }
            if (q[p].first > ans) {
                break;
            }
        }
        if (w[cur].size() == 0) {
            --ans;
            break;
        }
        while (!w[cur].empty()) {
            int t = w[cur].front();
            w[cur].pop();
            for (int j = -1; j <= 1; ++j) {
                if (t + j >= 0 && t + j < used.size()) {
                    if (!used[t + j]) {
                        used[t + j] = true;
                        ++sum;
                        w[!cur].push(t + j);
                    }
                }
            }
        }
        cur = !cur;
    }
    cout << ans << endl;
}