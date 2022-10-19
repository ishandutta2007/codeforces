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
        vector<vector<int>> s(k);
        vector<int> used(n, -1);
        for(int i = 0; i < k; ++i){
            int c;
            cin >> c;
            s[i].resize(c);
            for(int j = 0; j < c; ++j)
                cin >> s[i][j], used[s[i][j]-1] = i;
        }
        int m;
        cout << "? " << n << ' ';
        for(int i = 1; i <= n; ++i)
            cout << i << ' ';
        cout << endl;
        cin >> m;
        int l = 0, r = n;
        while(l < r-1){
            int m1 = (l+r)/2;
            cout << "? " << m1-l << ' ';
            for(int i = l; i < m1; ++i)
                cout << i+1 << ' ';
            cout << endl;
            int m2;
            cin >> m2;
            if(m2 == m)
                r = m1;
            else
                l = m1;
        }
        vector<int> ans(n);
        for(int i = 0; i < k; ++i)
            if(i != used[l])
                ans[i] = m;
        if(used[l] != -1){
            int k1 = 0;
            for(int i = 0; i < n; ++i)
                if(used[i] != used[l])
                    k1++;
            cout << "? " << k1 << ' ';
            for(int i = 0; i < n; ++i)
                if(used[i] != used[l])
                    cout << i+1 << ' ';
            cout << endl;
            int a;
            cin >> a;
            ans[used[l]] = a;
        }
        cout << "! ";
        for(int i = 0 ; i < k; ++i)
            cout << ans[i] << ' ';
        cout << endl;
        string s1;
        cin >> s1;
    }
}