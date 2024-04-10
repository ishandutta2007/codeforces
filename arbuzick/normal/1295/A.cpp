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
        string ans = "";
        if(n%2 == 0){
            ans += '1';
            n -= 2;
        }else{
            ans += '7';
            n -= 3;
        }
        for(int i = 0; i < n/2; ++i)
            ans += '1';
        cout << ans << '\n';
    }
    return 0;
}