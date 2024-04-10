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
typedef long double ld;
mt19937 rr(random_device{}());

const int MAXN = 1 << 14;
ll a[MAXN];

int main() {
    // freopen("input.txt", "r", stdin)p;
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
        
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        ++a[b];
    }

    if (k == 0) {
        ll ans = 0;
        for (int i = 0; i < MAXN; ++i)
            ans += a[i] * (a[i] - 1) / 2;
        cout << ans << endl;
        return 0;
    }

    vector<bool> cor(MAXN);
    for (int i = 0; i < MAXN; ++i) {
        if (__builtin_popcount(i) == k)
            cor[i] = true;
    }

    ll ans = 0;
    for (int i = 0; i < MAXN; ++i) {
        for (int j = i + 1; j < MAXN; ++j) {
            if (cor[i ^ j])
                ans += a[i] * a[j];
        }
    }

    cout << ans << endl;
}