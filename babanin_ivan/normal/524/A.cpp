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

map <int, int> lib;
map <int, int> rev;

int K = 0;



int getnum(int x) {
    if (lib.find(x) == lib.end()) {
        lib[x] = K;
        rev[K] = x;
        ++K;
    }
    return lib[x];
}

vector < vector <int> > g;

void solve() {
    int m, k;
    cin >> m >> k;

    vector < pair <int, int> > edges;


    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;

        edges.push_back(mp(getnum(x), getnum(y)));

    }

    g.resize(K);

    for (int i = 0; i < edges.size(); ++i) {
        g[edges[i].first].push_back(edges[i].second);

        swap(edges[i].first, edges[i].second);

        g[edges[i].first].push_back(edges[i].second);
    }

    vector <pair <int, vector <int> >> results;

    for (int i = 0; i < K; ++i) {
        vector <int> used(K, 0);
        results.push_back(mp(rev[i], vector <int>()));

        for (int t: g[i]) {
            used[t] = 1;
        }

        for (int j = 0; j < K; ++j) {
            if (used[j] || j == i) {
                continue;
            }

            int sum = 0;

            for (int u: g[j]) {
                if (used[u]) {
                    ++sum;
                }
            }

            if (sum * 100 >= k * g[i].size()) {
                results.back().second.push_back(rev[j]);
            }
        }
    }

    sort(results.begin(), results.end());

    for (auto tmp: results) {
        cout << tmp.first << ": " << tmp.second.size() << " ";

        sort(tmp.second.begin(), tmp.second.end());
        for (int x: tmp.second) {
            cout << x << " ";
        }
        cout << "\n";
    }
}