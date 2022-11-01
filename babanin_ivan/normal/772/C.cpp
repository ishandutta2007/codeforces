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

#define int li

int bpow(int x, int step, int mod) {
    if (step == 0) {
        return 1;
    }
    if (step == 1) {
        return x;
    }
    int tmp = bpow(x, step / 2, mod);
    tmp = (tmp * tmp) % mod;
    if (step & 1) {
        tmp = (tmp * x) % mod;
    }
    return tmp;
}

void solve() {
    int N, m;
    cin >> N >> m;
    vector <int> prohibited(m);
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        prohibited[x] = 1;
    }
    
    vector <vector <int> > to_div;
    
    int rest = m;
    for (int j = 2; j * j <= m; ++j) {
        if (rest % j == 0) {
            vector <int> cur;
            cur.push_back(1);
            while (rest % j == 0) {
                rest /= j;
                cur.push_back(cur.back() * j);
            }
            to_div.push_back(cur);
        }
    }
    if (rest != 1) {
        vector <int> cur = {1, rest};
        to_div.push_back(cur);
    }
    
    vector <int> allowed;
    for (int i = 1; i < m; ++i) {
        if (!prohibited[i]) {
            allowed.push_back(i);
        }
    }
        
    vector <vector <int> > groups(m);
    for (int x: allowed) {
        int from_m = 1;
        int from_x = x;
        
        for (int i = 0; i < to_div.size(); ++i) {
            for (int j = to_div[i].size() - 1; j >= 0; --j) {
                if (from_x % to_div[i][j] == 0) {
                    from_x /= to_div[i][j];
                    from_m *= to_div[i][j];
                    break;
                }
            }
        }
        
        groups[from_m].push_back(from_x);
    }
    
    int euler = 1;
    for (int i = 0; i < to_div.size(); ++i) {
        euler *= (to_div[i].back() - to_div[i][to_div[i].size() - 2]);
    }
    
    vector <int> dp(m);
    vector <int> from(m, -1);
    
    vector <int> divisors(m);
    for (int i = 1; i < m; ++i) {
        if (m % i == 0) {
            divisors[i] = 1;
        }
    }
    
    for (int i = 1; i < m; ++i) {
        if (!divisors[i]) {
            continue;
        }
        
        if (dp[i] < groups.size()) {
            dp[i] = groups.size();
        }
        
        for (int j = 0; j < to_div.size(); ++j) {
            int go = i * to_div[j][1];
            if (go >= m || !divisors[go]) {
                continue;
            }
            int to_upd = dp[i] + groups[go].size();
            if (dp[go] < to_upd) {
                dp[go] = to_upd;
                from[go] = i;
            }
        }
    }
    
    vector <int> groupspath;
    
    int best_val = 0;
    int best_start = -1;
    
    for (int i = 0; i < m; ++i) {
        if (dp[i] > best_val && groups[i].size()) {
            best_val = dp[i];
            best_start = i;
        }
    }
    
    vector <pair <int, int> > ans;
    
    while (best_start != -1) {
        for (int x: groups[best_start]) {
            ans.push_back(mp(best_start, x));
        }
        best_start = from[best_start];
    }
    reverse(all(ans));
    
    vector <int> result;
    
    for (int i = 0; i < ans.size(); ++i) {
        if (i == 0) {
            result.pb(ans[i].first * ans[i].second);
        } else {
            int first_part = ans[i].first / ans[i - 1].first;
            int second_part = (ans[i].second * bpow(ans[i - 1].second, euler - 1, m)) % m;
            result.pb((first_part * second_part) % m);
        }
    }
    
    if (!prohibited[0]) {
        result.push_back(0);
    }
    cout << result.size() << "\n";
    for (int x: result) {
        cout << x << " ";
    }
    //rememver about 0!!!
}