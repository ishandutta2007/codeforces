#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;


int main() {
    long long n;
    long long A, cf, cn, m;
    cin >> n >> A >> cf >> cn >> m;
    vector< pair<long long, int> > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    long long ans = -1;
    int p = -1, q = -1;
    vector<long long> suff(n + 1), pref(n);
    suff[n] = 0;
    pref[0] = 0;
    for (long long i = n - 1; i >= 0; i--)
        suff[i] = suff[i + 1] + (A - a[i].first);
    pref[0] = 0;
    for (long long i = 1; i < n; i++)
        pref[i] = pref[i - 1] + (a[i].first - a[i - 1].first) * i;
    if (suff[0] <= m) {
        ans = n * cf + A * cn;
        cout << ans << endl;
        for (int i = 0; i < n; i++)
            cout << A << " ";
        cout << endl;
        return 0;
    }
    for (long long i = 1; i <= n; i++) {
        if (suff[i] > m)
            continue;
        long long cur = (n - i) * cf;
        long long l = 0, r = n;
        while (r - l > 1) {
            long long x = (l + r) / 2;
            if (pref[x] <= m - suff[i])
                l = x;
            else
                r = x;
        }
        l = min(l, i - 1);
        cur += (a[l].first + (m - pref[l] - suff[i]) / (l + 1)) * cn;
        if (ans < cur) {
            ans = cur;
            p = l;
            q = i;
        }
    }
    cout << ans << endl;
    vector<long long> b(n);
    for (int i = 0; i < n; i++)
        b[a[i].second] = a[i].first;
    for (int i = q; i < n; i++)
        b[a[i].second] = A;
    for (int i = 0; i <= p; i++)
        b[a[i].second] = a[p].first + (m - pref[p] - suff[q]) / (p + 1);
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << endl;
    
    return 0;
}