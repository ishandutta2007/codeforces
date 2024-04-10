#include <bits/stdc++.h>

using namespace std;

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s, t;
    bool f;
    for (int i = 1; i <= n; ++i){
        cin >> s >> t;
        int cnt1 = 0, cnt2 = 0;
        f = true;
        int it = 0, it1 = 0;
        while (it < (int)s.size() && it1 < (int)t.size()){
            if (s[it] != t[it1]){
                f = false;
                break;
            }
            char x1 = s[it];
            cnt1 = 0, cnt2 = 0;
            while (it < (int)s.size() && s[it] == x1) it++, cnt1++;
            x1 = t[it1];
            while (it1 < (int)t.size() && t[it1] == x1) it1++, cnt2++;
            if (cnt2 < cnt1) f = false;
        }
        if (it != (int)s.size()) f = false;
        if (it1 != (int)t.size()) f = false;
        if (f) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}