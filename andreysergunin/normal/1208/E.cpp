#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>
#include <chrono>
#include <climits>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
// mt19937 rnd(1);

 
struct Queue {
 
    void push(int x) {
        a.push_back(x);
        if (ma.empty()) {
            ma.push_back(x);
        } else {
            ma.push_back(max(x, ma.back()));
        }
    }
 
    void pop() {    
        if (sz(b) == 0) {
            rebuild();
        }
        b.pop_back();
        mb.pop_back();
    }
 
    void rebuild() {
        for (int i = sz(a) - 1; i >= 0; --i) {
            b.push_back(a[i]);
            if (sz(mb) > 0) {
                mb.push_back(max(mb.back(), a[i]));
            } else {
                mb.push_back(a[i]);
            }
        }
        a.clear();
        ma.clear();
    }
 
    int get() {
        if (sz(a) == 0) {
            return mb.back();
        }
        if (sz(b) == 0) {
            return ma.back();
        }
        return max(ma.back(), mb.back());
    }
 
    vector<int> a;
    vector<int> ma;
    vector<int> b;
    vector<int> mb;
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif
    
    int n, w;
    cin >> n >> w;
 
    vector<ll> diff(w);
 
    for (int t = 0; t < n; ++t) {
        int k;
        cin >> k;
        vector<int> a(k);
        for (int i = 0; i < k; ++i) {
            cin >> a[i];
        }
 
        vector<int> pos;
        vector<int> l, r;
        
        if (2 * k + 2 >= w) {
            for (int i = 0; i < w; ++i) {
                pos.push_back(i);
                l.push_back(max(0, i - (w - k)));
                r.push_back(min(i, k - 1));
            }
        } else {
            for (int i = 0; i < k + 1; ++i) {
                pos.push_back(i);
                l.push_back(max(0, i - (w - k)));
                r.push_back(min(i, k - 1));
            }
            for (int i = w - k - 1; i < w; ++i) {
                pos.push_back(i);
                l.push_back(max(0, i - (w - k)));
                r.push_back(min(i, k - 1));
            }
        }
 
        int lf = 0, rg = -1;
 
        vector<int> res = {0};
        
        Queue q;
 
        for (int i = 0; i < sz(pos); ++i) {
            while (rg != r[i]) {
                ++rg;
                q.push(a[rg]);
            }
            while (lf != l[i]) {
                ++lf;
                q.pop();
            }

            res.push_back(q.get());
        }
 
        for (int i = 0; i < sz(pos); ++i) {
            if (pos[i] + k < w || k <= pos[i]) {
                res[i + 1] = max(res[i + 1], 0);
            }
        }
 
        // for (int i = 0; i < sz(pos) + 1; ++i) {
        //     cout << res[i] << " ";
        // }
        // cout << endl;
 
 
        for (int i = 0; i < sz(pos); ++i) {
            diff[pos[i]] += res[i + 1] - res[i];
        }
    }
 
    vector<ll> res(w);
    for (int i = 0; i < w; ++i) {
        if (i > 0) {
            res[i] = res[i - 1];
        }
        res[i] += diff[i];
    }
 
    for (int i = 0; i < w; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
 
}