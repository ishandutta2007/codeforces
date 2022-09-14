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

int main() {
    int n;
    long long a, b, T;
    cin >> n >> a >> b >> T;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < 2; i++) {
        long long t = 1;
        if (s[0] == 'w')
            t += b;
        if (t > T) {
            cout << 0 << endl;
            return 0;
        }
        if (n == 1) {
            cout << 1 << endl;
            return 0;
        }
        ans = max(1, ans);
        
        vector<long long> pref(n);
        pref[1] = 0;
        for (int i = 2; i < n; i++) {
            pref[i] = pref[i - 1] + 1 + a;
            if (s[i] == 'w')
                pref[i] += b;
        }
        
        for (int i = n - 1; i >= 1; i--) {
            int cur = n - i + 1;
            t += a;
            if (s[i] == 'w')
                t += b;
            t += 1;
            if (t > T)
                continue;
            ans = max(ans, cur);
            if (i == 1)
                continue;
            long long t1 = t;
            t1 += (n - i + 1) * a;
            t1 += 1;
            if (s[1] == 'w')
                t1 += b;
            if (t1 > T)
                continue;
            int l = 1;
            int r = i;
            while (r - l > 1) {
                int m = (l + r) / 2;
                if (pref[m] + t1 <= T)
                    l = m;
                else
                    r = m;
            }
            cur += l;
            ans = max(ans, cur);
        }
        reverse(s.begin() + 1, s.end());
    }
    cout << ans << endl;
    
    return 0;
}