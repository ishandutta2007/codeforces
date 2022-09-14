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
 
    int res = n;
 
    for (int l = 0; l < n; ++l) {
        set<int> setik;
        bool ok = true;
 
        for (int i = 0; i < l; ++i) {
            if (setik.count(a[i])) {
                ok = false;
            }
            setik.insert(a[i]);
        }
        if (!ok) {
            continue;
        }
        res = min(res, n - l);
 
        for (int r = n - 1; r >= l; --r) {
            if (setik.count(a[r])) {
                break;
            }
            setik.insert(a[r]);
            res = min(res, r - l);
        }
    }    
 
    cout << res << endl;
 
}