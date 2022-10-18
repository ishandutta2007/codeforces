#include <bits/stdc++.h>

using namespace std;

#define int long long
string s;

bool check(int l, int r){
    if (r - l + 1 >= 9) return true;
    for (int i = l; i < r; ++i){
        for (int j = i + 1; j < r; ++j){
            int k = j - i;
            int go = i + 2 * k;
            if (go > r) break;
            if (s[i] == s[j] && s[j] == s[go]) return true;
        }
    }
    return false;
}

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    int n = s.size();
    int l = 0, r = 0;
    int ans = 0;
    while (r < n){
        r = max(r, l + 2);
        while (r < n && !(check(l, r))){
            ++r;
        }
        if (r >= n) break;
        ans += (n - r);
        ++l;
    }
    cout << ans << '\n';
    return 0;
}