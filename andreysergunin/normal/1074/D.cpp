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

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int uint;

mt19937 rnd(random_device{}());

map<int, int> p;
map<int, int> w;
map<int, int> f;

pair<int, int> get(int v) {
    int u = p[v];
    if (u == v) {
        return {v, 0};
    }
    pair<int, int> res = get(u);
    res.second ^= f[v];
    p[v] = res.first;
    f[v] = res.second;
    return res;
}

void unite(int v, int u, int x) {
    if (u == v) {
        return;
    }
    if (w[v] < w[u]) {
        swap(v, u);
    }
    p[u] = v;
    w[v] += w[u];
    f[u] = x;
}

int main() {
    
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
    
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
    

    int n;
    cin >> n;

    int last = 0;
    for (int i = 0; i < n; ++i) {
        int type;
        cin >> type;
        int u, v;
        cin >> u >> v;
        u ^= last;
        v ^= last;

        if (u > v) {
            swap(u, v);
        }
        
        ++v;

        if (!p.count(u)) {
            p[u] = u;
            f[u] = 0;
            w[u] = 1;
        }

        if (!p.count(v)) {
            p[v] = v;
            f[v] = 0;
            w[v] = 1;
        }

        

        if (type == 1) {
            int x;
            cin >> x;
            x ^= last;
            pair<int, int> p = get(u);
            pair<int, int> q = get(v);
            unite(p.first, q.first, x ^ p.second ^ q.second);
        } else {
            pair<int, int> p = get(u);
            pair<int, int> q = get(v);
            if (p.first == q.first) {
                int res = (p.second ^ q.second);
                cout << res << endl;
                last = res;
            } else {
                cout << -1 << endl;
                last = 1;
            }
        }
    }
    
}