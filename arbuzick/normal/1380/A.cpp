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
        vector<int> p(n);
        for(int i = 0; i < n; ++i)
            cin >> p[i];
        bool ans = 0;
        int i, j, k;
        for(int j1 = 1; j1+1 < n; ++j1){
            int i1 = -1, k1 = -1;
            for(int i2 = 0; i2 < j1; ++i2)
                if(p[i2] < p[j1])
                    i1 = i2;
            for(int k2 = j1+1; k2 < n; ++k2)
                if(p[k2] < p[j1])
                    k1 = k2;
            if(k1 != -1 && i1 != -1){
                ans = 1, i = i1, j = j1, k = k1;
                break;
            }
        }
        if(ans)
            cout << "YES\n" << i+1 << ' ' << j+1 << ' ' << k+1 << '\n';
        else
            cout << "NO\n";
    }
	return 0;
}