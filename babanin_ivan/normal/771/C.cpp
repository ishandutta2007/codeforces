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
#define all(a) a.begin(), a.end()

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

vector <vector <int> > g;

#define int li


int n, k;

int global_ans = 0;

pair <int, vector <int> > dfs(int v, int p) {
    
    int sumfull = 0;
    vector <int> cur_mod(k);
    
    
    for (int to: g[v]) {
        if (to == p) {
            continue;
        }
        auto to_res = dfs(to, v);
        
        int cursum_verts_left = 0;
        int cursum_verts_right = 0;
        for (int i = 0; i < k; ++i) {
            cursum_verts_left += cur_mod[i];
            cursum_verts_right += to_res.second[i];
        }
        global_ans += cursum_verts_right * sumfull;
        global_ans += cursum_verts_left * to_res.first;
        
        for (int j = 0; j < k; ++j) {
            for (int i = 0; i < k; ++i) {
                int sum_dists = i + j + 2;
                global_ans += cur_mod[i] * to_res.second[j] * ((sum_dists + k - 1) / k);
            }
        }
        
        sumfull += to_res.first;
        for (int j = 0; j < k; ++j) {
            cur_mod[j] += to_res.second[j];
        }
    }
    
    sumfull += cur_mod.back();
    
    int tmp = cur_mod.back();
    for (int i = int(cur_mod.size()) - 2; i >= 0; --i) {
        cur_mod[i + 1] = cur_mod[i];
    }
    cur_mod[0] = tmp;
    
    global_ans += sumfull;
    for (int i = 1; i < k; ++i) {
        global_ans += cur_mod[i];
    }
    
    cur_mod[0]++;
    
    return mp(sumfull, cur_mod);
}

void solve() {
    cin >> n >> k;
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    auto res = dfs(0, -1);
    cout << global_ans << endl;
}