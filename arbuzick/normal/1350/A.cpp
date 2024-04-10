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
        int n, k;
        cin >> n >> k;
        for(int i = 2; i <= n; ++i)
            if(n%i == 0){
                cout << n+i+(k-1)*2 << '\n';
                break;
            }
    }
    return 0;
}