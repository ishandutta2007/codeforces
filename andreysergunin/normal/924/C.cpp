#include <stdio.h>
#include <iostream>
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
typedef double ld;

int main() {    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
        
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> pref(n + 1);

    pref[0] = 0;
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = max(pref[i], a[i]);
    }

    int cur = pref[n];
    ll ans = 0;

    vector<int> f(n);

    for (int i = n - 1; i >= 0; --i) {
        f[i] = cur;
        ans += cur - a[i];
        cur = max(cur - 1, pref[i]);
    }

    // for (int i = 0; i < n; ++i) {
    //     cout << f[i] << " ";
    // }
    // cout << endl;

    cout << ans << endl;

}