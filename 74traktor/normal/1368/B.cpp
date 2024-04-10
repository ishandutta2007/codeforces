/*
,  ?  ?
 Cadillac
 ,  
 , ,   (, few)
*/
#include<bits/stdc++.h>

using namespace std;

#define int long long

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    string s = "codeforces";
    vector < int > a;
    for (int i = 0; i < (int)s.size(); ++i) a.push_back(1);
    int t = 1, pos = 0;
    while (t < k) {
        a[pos]++;
        t = 1;
        for (int j = 0; j < (int)s.size(); ++j) t *= a[j];
        pos = (pos + 1) % (int)s.size();
    }
    for (int i = 0; i < (int)s.size(); ++i) {
        for (int j = 0; j < a[i]; ++j) cout << s[i];
    }
    return 0;
}