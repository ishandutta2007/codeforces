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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);

int request(vector<int> p, vector<int> q) {
    cout << sz(p) << " " << sz(q) << " ";
    for (int i = 0; i < sz(p); ++i) {
        cout << p[i] + 1 << " ";
    }
    for (int i = 0; i < sz(q); ++i) {
        cout << q[i] + 1 << " ";
    }
    cout << endl;
    int res = 0;
    cin >> res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tests;
    cin >> tests;

    for (int test = 0; test < tests; ++test) {
        int n;
        cin >> n;
        int res = 0;
        for (int i = 0; i < 7; ++i) {
            vector<int> p, q;
            for (int j = 0; j < n; ++j) {
                if (j & (1 << i)) {
                    p.push_back(j);
                } else {
                    q.push_back(j);
                }
            }

            if (sz(p) > 0 && sz(q) > 0) {
                res = max(res, request(p, q));
            }
        }   

        cout << -1 << " " << res << endl;
    }



    
    
}