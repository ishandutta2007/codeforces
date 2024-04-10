#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int mnr = 1e9;
        int mnc = 1e9;
        int mxr = 0;
        int mxc = 0;
        int br;
        vector<pair<int,int>> robots;
        for(int ri = 0; ri < n; ri ++) {
            for(int ci = 0; ci < m; ci ++) {
                char c;
                cin >> c;
                if(c == 'R') {
                    if(ri < mnr) {
                        mnr = ri;
                        br = ci;
                    }
                    if(ci < mnc) {
                        mnc = ci;
                    }
                }
            }
        }
        if(br == mnc) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        
    }
    return 0;
}