#include <bits/stdc++.h>

using namespace std;

vector<int> L(300006,1000000000);
vector<int> R(300006,-1);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        vector<int> as(n);
        int d = 0;
        for(int i = 0; i < n ; i ++) {
            int a;
            cin >> a;
            as[i] = a;
            L[a] = min(L[a],i);
            R[a] = max(R[a],i);
        }
        sort(as.begin(), as.end());
        int lst = 0;
        L[0] = -1;
        R[0] = -1;
        int cnt = 0;
        int res = 0;
        for(int a: as) {
            if(lst == a) { continue; }
            d ++;
            // cout << "  " << lst << " " << a << " " << R[lst] << " " << L[a] << "\n";
            if(R[lst] < L[a]) {
                cnt ++;
            } else {
                res = max(cnt,res);
                cnt = 1;
            }
            lst = a;
        }
        res = max(res,cnt);
        for(int a : as) {
            L[a] = 1000000000;
            R[a] = -1;
        }
        cout << (d-res) << "\n";
    }
    return 0;
}