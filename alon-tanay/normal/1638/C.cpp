#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t --) {
        int n;
        cin >> n;
        vector<int> loc(n);
        vector<int> xs(n);
        for(int i = 0; i < n; i ++) {
            int x;
            cin >> x; x--;
            loc[x] = i;
            xs[i] = x;
        }
        int mxloc = -1;
        int res = 0;
        
        int mx = -1;
        for(int i = 0; i < n; i ++) {
            if(loc[i] > mxloc) {
                if(mx < i) {
                    res ++;
                }
                for(int j = mxloc + 1; j <= loc[i]; j ++) {
                    mx = max(mx,xs[j]);
                }
                mxloc = loc[i];
                
            }
        }
        cout << res << "\n";
    }

    return 0;
}