#include <bits/stdc++.h>

using namespace std;

const long long N = 4e5 + 5, MOD = 998244353;



int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int ans = 0;
        for (int m = 3; m <= 1000; m++){
            if (m * n % 180 != 0)
                continue;
            int k = m * n / 180;
            if (k <= m - 2){
                ans = m;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}