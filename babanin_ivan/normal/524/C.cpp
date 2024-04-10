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
    while (t--) {
        //++timer;
        solve();
    }
#ifdef YA
    cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
    return 0;
}

int n, k;

void solve() {
    cin >> n >> k;
    
    vector <int> a(n);

    vector <pair <int, int> > b;
    b.reserve(k * n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pair <int, int> sum = mp(0, 0);
        for (int j = 0; j < k; ++j) {
            sum.first += a[i];
            sum.second ++;
            b.push_back(sum);
        }
    }

    vector <pi> c;

    b.push_back(mp(0, 0));

    sort(b.begin(), b.end());

    for (int i = 0; i < b.size(); ++i) {
        if (i == 0 || b[i].first != b[i - 1].first) {
            c.push_back(b[i]);
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int xi;
        cin >> xi;
        int ans = k + 1;

        int right = c.size() - 1;
        for (int left = 0; left < c.size(); ++left) {
            while (right >= 0 && c[right].first + c[left].first > xi) {
                --right;
            }
            if (right >= 0 && c[left].first + c[right].first == xi) {
                if (ans == -1 || c[left].second + c[right].second < ans) {
                    ans = c[left].second + c[right].second;
                }
            }
        }

        if (ans > k) {
            ans = -1;
        }
        cout << ans << "\n";
    }
}