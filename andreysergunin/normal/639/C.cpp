#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>
#include <queue>

using namespace std;

#define sz(a) (int)a.size()
#define all(a) (a).begin(), (a).end()

const long long INF = 1e18;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n + 1);
    for (int i = 0; i <= n; ++i)
        cin >> a[i];
    vector<long long> suff(n + 1);
    suff[n] = a[n];
    for (int i = n - 1; i >= 0; --i) {
        suff[i] = suff[i + 1] * 2 + a[i];
        if (abs(suff[i]) > k) {
            for (int j = 0; j < i; ++j)
                suff[j] = INF;
            break;
        }
    }
    
    vector<long long> pref(n + 1);
    pref[0] = 0;
    for (int i = 1; i <= n; ++i) {
        if ((pref[i - 1] + a[i - 1]) % 2 != 0) {
            for (int j = i; j <= n; ++j)
                pref[j] = INF;
            break;
        }
        pref[i] = (pref[i - 1] + a[i - 1]) / 2;
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (pref[i] + suff[i] < INF) {
            long long u = pref[i] + suff[i];
            if (abs(a[i] - u) <= k && !(a[n] == u && i == n) )
                ++ans;
        }
    }
    cout << ans << endl;
    
    return 0;
}