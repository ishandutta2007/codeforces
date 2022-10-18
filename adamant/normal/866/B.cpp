#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, st;
    cin >> n >> st;
    int s[n], a[n], b[n];
    int ans = 0;
    int need_a = 0, need_b = 0;
    int total = 0;
    map<int, int> not_a, not_b;
    for(int i = 0; i < n; i++) {
        cin >> s[i] >> a[i] >> b[i];
        total += s[i];
        if(a[i] > b[i]) {
            need_a += s[i];
            not_a[a[i] - b[i]] += s[i];
            ans += a[i] * s[i];
        } else {
            ans += b[i] * s[i];
            need_b += s[i];
            not_b[b[i] - a[i]] += s[i];
        }
    }
    int rmd = (st - total % st) % st;
    
    int check_a = 0, check_b = 0;
    int fuck_a = max((st - need_b % st) % st - rmd, (int)0), fuck_b = max((st - need_a % st) % st - rmd, (int)0);
    for(auto it: not_a) {
        int t = min(fuck_a, it.second);
        check_a += it.first * t;
        fuck_a -= t;
    }
    for(auto it: not_b) {
        int t = min(fuck_b, it.second);
        check_b += it.first * t;
        fuck_b -= t;
    }
    
    cout << ans - min(check_a, check_b) << endl;
    
}

/* 
 * This problem is so fucked up, I hate it!
 */