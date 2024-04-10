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
#include <complex>
#include <bitset>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();

    int n;
    ll c;
    cin >> n >> c;
    vector<ll> s(2 * n - 1);
    for (int i = 0; i < 2 * n - 1; ++i) {
        cin >> s[i];
        s[i] = min(s[i], c);
    }
    vector<ll> pref(2 * n);
    for (int i = 0; i < 2 * n - 1; ++i) {
        pref[i + 1] = pref[i] + s[i];
    }

    ll toAdd = 0;
    set<pair<ll, int>> setik;
    vector<ll> f(n), g(n);
    int l = 0;
    f[0] = s[0];
    g[0] = s[0];
    setik.insert({g[0], 0});

    for (int i = 1; i < n; ++i) {
        f[i] = s[2 * i] + f[i - 1];
        toAdd += s[2 * i] + s[2 * i - 1];
        for (; l < i && pref[2 * i + 1] - pref[2 * l] > c; ++l) {
            f[i] = max(f[i], (l > 0 ? f[l - 1] : 0) + c);
            setik.erase({g[l], l});
        }

        if (!setik.empty()) {
            pair<ll, int> p = *(--setik.end());
            f[i] = max(f[i], p.first + toAdd);
        }
        g[i] = f[i - 1] + s[2 * i] - toAdd;
        setik.insert({g[i], i});
    }
    cout << f[n - 1] << endl;
}