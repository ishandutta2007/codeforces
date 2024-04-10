#include <bits/stdc++.h>

using namespace std;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n % 2 == 1){
        cout << ":(" << '\n';
        return 0;
    }
    int cnt1 = 0, cnt2 = 0;
    for (auto c : s){
        if (c == '(') cnt1++;
        if (c == ')') cnt2++;
    }
    if (max(cnt1, cnt2) > n / 2){
        cout << ":(" << '\n';
        return 0;
    }
    for (int i = 0; i < n; ++i){
        if (cnt1 == n / 2) break;
        if (s[i] == '?'){
            s[i] = '(';
            cnt1++;
        }
    }
    for (int i = 0; i < n; ++i){
        if (s[i] == '?') s[i] = ')';
    }
    int bal = 0, kk = 0;
    for (auto c : s){
        if (c == '(') bal++;
        else bal--;
        if (bal < 0 || (bal == 0 && kk == 1)){
            cout << ":(" << '\n';
            return 0;
        }
        else if (bal == 0) kk = 1;
    }
    cout << s << '\n';
    return 0;
}