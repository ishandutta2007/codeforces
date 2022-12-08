#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int m;
        cin >> m;
        vector<int> as(m);
        vector<int> bs(m);
        for(int &a : as) {
            cin >> a; a++;
        }
        for(int &b : bs) {
            cin >> b; b++;
        }
        as[0] = 0;
        vector<int> dpA_l(m+1);
        vector<int> dpB_l(m+1);
        vector<int> dpA_r(m+1);
        vector<int> dpB_r(m+1);
        dpA_l[m] = -1e9;
        dpB_l[m] = -1e9;
        dpA_r[m] = -1e9;
        dpB_r[m] = -1e9;
        for(int i = m - 1; i >= 0; i --) {
            dpA_r[i] = max(dpA_r[i+1]+1,as[i]);
            dpB_r[i] = max(dpB_r[i+1]+1,bs[i]);
            dpA_l[i] = max(dpA_l[i+1],as[i]+(m-i-1));
            dpB_l[i] = max(dpB_l[i+1],bs[i]+(m-i-1));
        }
        int res = 2e9;
        int pre = -1;
        int tim;
        for(int i = 0; i < m; i ++) {
            if(i&1) {
                pre = max(pre+1,bs[i]);
                tim = max(pre+(2*m-2*i-1),max(dpB_l[i]+(m-i),dpA_r[i]));
                // cout << "bot " << i << ": " << tim << " (pre: " << pre+(2*m-2*i-1) << ", nat: " << pre << ", to end: " << dpB_l[i]+(m-i) << ", and back: " << dpA_r[i] << ")\n";
                res = min(res,tim);

                pre = max(pre+1,as[i]);
                tim = max(pre+(2*m-2*i-2),max(dpA_l[i]+(m-i-1),dpB_r[i+1]));
                // cout << "top " << i << ": " << tim << " (pre: " << pre+(2*m-2*i-2) << ", nat: " << pre << ", to end: " << dpA_l[i]+(m-i-1) << ", and back: " << dpB_r[i+1] << ")\n";
                res = min(res,tim);
            } else {
                pre = max(pre+1,as[i]);
                tim = max(pre+(2*m-2*i-1),max(dpA_l[i]+(m-i),dpB_r[i]));
                // cout << "top " << i << ": " << tim << " (pre: " << pre+(2*m-2*i-1) << ", nat: " << pre << ", to end: " << dpA_l[i]+(m-i) << ", and back: " << dpB_r[i] << ")\n";
                res = min(res,tim);

                pre = max(pre+1,bs[i]);
                tim = max(pre+(2*m-2*i-2),max(dpB_l[i]+(m-i-1),dpA_r[i+1]));
                // cout << "bot " << i << ": " << tim << " (pre: " << pre+(2*m-2*i-2) << ", nat: " << pre << ", to end: " << dpB_l[i]+(m-i-1) << ", and back: " << dpA_r[i+1] << ")\n";
                res = min(res,tim);
            }
        }
        cout << res << "\n";
    }
    return 0;
}