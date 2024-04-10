#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n+1);
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        vector<string> s(n+2);
        for(int i = 0; i < 50; ++i)
            s[0] += 'a';
        for(int i = 1; i < n+2; ++i){
            for(int j = 0; j < a[i-1]; ++j)
                s[i] += s[i-1][j];
            s[i] += char('a'+(s[i-1][a[i-1]]+1)%26);
            for(int j = a[i-1]+1; j < 50; ++j)
                s[i] += 'a';
        }
        for(int i = 1; i < n+2; ++i)
            cout << s[i] << '\n';
    }
    return 0;
}