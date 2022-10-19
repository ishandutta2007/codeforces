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
        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        for(int i = 32; i >= -1; --i){
            if(i == -1){
                cout << "DRAW\n";
                continue;
            }
            int k = 0;
            for(int j = 0; j < n; ++j)
                k = k+(((1LL << i)&a[j]) >> i);
            if(k%2 == 0)
                continue;
            if(k%4 == 1){
                cout << "WIN\n";
            }else{
                if(n%2 == 1)
                    cout << "LOSE\n";
                else
                    cout << "WIN\n";
            }
            break;
        }
    }
    return 0;
}