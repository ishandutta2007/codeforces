#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.length();
        int ones = 0;
        vector<int> one;
        int sz = 0;
        for(char c : s) {
            if(c == '1') {
                ones ++;
                sz ++;
            } else {
                one.push_back(sz);
                sz = 0;
            }
        }
        one.push_back(sz);
        int l = 0, r = n-ones;
        // cout << "yo" << endl;
        while(l < r) {
            int mid = (l+r)/2;
            int sum = 0;
            for(int i = 0; i <= mid; i ++) {
                sum += one[i];
            }
            int mx = sum;
            // cout << mx << endl;
            for(int i = mid + 1; i < one.size(); i ++) {
                sum -= one[i-mid-1];
                sum += one[i];
                mx = max(mx,sum);
            }
            // cout << mx << endl;
            int res = ones - mx;
            if(res <= mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << l << "\n";
        continue;
        // int mxp = 0;
        // int cr = 0;
        // int res = 0;
        // for(int i = 0; i < n; i ++) {
        //     if(s[i] == '1') {
        //         cr --;
        //     } else {
        //         cr ++;
        //     }
        //     cout << cr << " " << mxp << "\n";   
        //     mxp = max(mxp,cr);
        //     res = min(res,cr-mxp);
        // }
        // cout << (res+ones) << "\n";
    }
    return 0;
}