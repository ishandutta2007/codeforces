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


int cnt[1 << 21];
int used[1 << 21];

int num = 0;
void add(int x) {
    ++num;
    queue<int> q;
    q.push(x);
    used[x] = num;


    while (!q.empty()) {    
        int x = q.front();
        q.pop();

        ++cnt[x];

        if (cnt[x] >= 3) {
            continue;
        }
        for (int i = 0; i < 21; ++i) {
            if (x & (1 << i) && used[x ^ (1 << i)] != num) {
                q.push(x ^ (1 << i));
                used[x ^ (1 << i)] = num;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif
    
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int res = 0;

    for (int i = n - 1; i >= 0; --i) {
        int mask = 0;
        int cur = 0;

        for (int b = 20; b >= 0; --b) {
            if (a[i] & (1 << b)) {
                cur ^= (1 << b);
            } else {
                if (cnt[mask ^ (1 << b)] >= 2) {
                    cur ^= (1 << b);
                    mask ^= (1 << b);
                }
            }
        }
        if (i <= n - 3) {
            res = max(res, cur);
        }

        add(a[i]);
    }

    // for (int i = 0; i < 8; ++i) {
    //     cout << cnt[i] << " ";
    // }
    // cout << endl;

    cout << res << endl;


 
}