#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 5e5 + 42;

int par[maxn], val[maxn];

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    char cur = 'a';
    int cnt[3] = {0, 0, 0};
    for(auto c: s) {
        beg:
        if(cur > 'c') {
            cout << "NO" << endl;
            return 0;
        }
        if(cur == c) {
            cnt[c - 'a']++;
        } else if(cnt[cur - 'a'] == 0) {
            cout << "NO" << endl;
            return 0;
        } else {
            cur++;
            goto beg;
        }
    }
    if(cur == 'c' && (cnt[2] == cnt[0] || cnt[2] == cnt[1])) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}