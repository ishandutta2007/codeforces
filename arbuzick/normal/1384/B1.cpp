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
        int n, k, l;
        cin >> n >> k >> l;
        vector<int> d(n);
        for(int i = 0; i < n; ++i)
            cin >> d[i];
        vector<int> k2(k*2);
        for(int i = 1; i <= k; ++i)
            k2[i] = k2[i-1]+1;
        for(int i = k+1; i < k*2; ++i)
            k2[i] = k2[i-1]-1;
        vector<vector<int>> a(n+1, vector<int>(k*2));
        for(int i = 0; i < k*2; ++i)
            a[0][i] = 1;
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < 2*k; ++j)
                if(d[i-1]+k2[j] <= l)
                    a[i][j] = a[i-1][(j-1+k*2)%(k*2)];
            for(int j = 0; j < k*2; ++j)
                if(d[i-1]+k2[j] <= l)
                    a[i][j] = a[i][j]|a[i][(j-1+k*2)%(k*2)];
            for(int j = 0; j < k*2; ++j)
                if(d[i-1]+k2[j] <= l)
                    a[i][j] = a[i][j]|a[i][(j-1+k*2)%(k*2)];
        }
        bool f = 0;
        for(int i = 0; i < k*2; ++i)
            f = f||a[n][i];
        if(f)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}