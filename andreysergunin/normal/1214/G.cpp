#pragma GCC optimize("Ofast", "unroll-loops")
 
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
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
// mt19937 rnd(1);
 
 
const int MAXN  = 2020;
bitset<MAXN> b[MAXN];
bitset<MAXN> p[MAXN];
bitset<MAXN> tmp;

int ok[MAXN][MAXN];
 
int cnt[MAXN];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        p[i + 1] = p[i];
        p[i + 1][i] = 1;
    }
 
    set<pii> setik;
    for (int i = 0; i < n; ++i) {
        setik.insert({cnt[i], i});
    }

    int q;
    cin >> q;
 
    vector<pii> good;
 
    for (int test = 0; test < q; ++test) {
        int i, l, r;
        cin >> i >> l >> r;
        --i; --l;

        auto it = setik.find({cnt[i], i});
        if (it != setik.begin()) {
            auto it1 = it;
            --it1;
            int u = it->second;
            int v = it1->second;
 
            if ((b[u] | b[v]) != b[u]) {
                ok[u][v] = false;
            }
        }

        auto it1 = it;
        ++it1;
 
        if (it1 != setik.end()) {
            int u = it1->second;
            int v = it->second;
            if ((b[u] | b[v]) != b[u]) {
                ok[u][v] = false;
            }
        }
 
        if (it != setik.begin() && it1 != setik.end()) {
            auto it2 = it;
            --it2;
            int v = it2->second;
            int u = it1->second;
            if ((b[u] | b[v]) != b[u]) {
                ok[u][v] = true;
                good.push_back({u, v});
            }
        }

        setik.erase({cnt[i], i});

        b[i] ^= p[l] ^ p[r];
        cnt[i] = b[i].count();

        setik.insert({cnt[i], i});

        it = setik.find({cnt[i], i});

        if (it != setik.begin()) {
            auto it1 = it;
            --it1;
            int u = it->second;
            int v = it1->second;
 
            if ((b[u] | b[v]) != b[u]) {
                ok[u][v] = true;
                good.push_back({u, v});
            }
        }
        it1 = it;
        ++it1;

        if (it1 != setik.end()) {
            int u = it1->second;
            int v = it->second;
            if ((b[u] | b[v]) != b[u]) {
                ok[u][v] = true;
                good.push_back({u, v});
            }
        }

        if (it != setik.begin() && it1 != setik.end()) {
            auto it2 = it;
            --it2;
            int v = it2->second;
            int u = it1->second;
            if ((b[u] | b[v]) != b[u]) {
                ok[u][v] = false;
            }
        }

        while (sz(good) > 0 && !ok[good.back().first][good.back().second]) {
            good.pop_back();
        }

        if (sz(good) == 0) {
            cout << -1 << endl;
            continue;
        } 

        auto itt = good.end();
        --itt;
        int u = itt->first;
        int v = itt->second;

        int p = (b[u] & (~b[v]))._Find_first();
        int q = (b[v] & (~b[u]))._Find_first();

        if (p > q) {
            swap(p, q);
        }
 
        if (u > v) {
            swap(u, v);
        }
 
        cout << u + 1 << " " << p + 1 << " " << v + 1 << " " << q + 1 << endl;
    }
 
#ifdef LOCAL
    cerr << "Time: " << ld(clock()) / CLOCKS_PER_SEC << endl;
#endif
}