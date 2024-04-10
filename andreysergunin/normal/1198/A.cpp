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
// default_random_engine generator;
// mt19937 rnd(1);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  

    int n, m;
    cin >> n >> m;
    m *= 8;

    int l = m / n;

    int k = 1;
    for (int i = 0; i < min(20, l); ++i) {
        k *= 2;
    }

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(all(a));

    vector<int> c;   
    c.push_back(1);
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            ++c.back(); 
        } else {
            c.push_back(1);
        }
    }
    vector<int> suff(sz(c) + 1);
    for (int i = sz(c) - 1; i >= 0; --i) {
        suff[i] = suff[i + 1] + c[i];
    }

        
    int res = n;

    int sum = 0;    
    for (int i = 0; i < sz(c); ++i) {
        int j = min(sz(c), i + k);
        res = min(res, suff[j] + sum);
        sum += c[i];
    }
    cout << res << endl;
}