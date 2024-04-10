#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define MOD 998244353
#define pi pair<int,int>
#define f first
#define s second

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> cs(n);
        vector<int> res(n);
        bool fail = true;
        for(int &c : cs) {
            cin >> c;
            if(c > 0) { fail = false; }
        }
        if(fail) {
            for(int i = 0; i < n; i ++) {
                cout << "0 ";
            }
            cout << "\n";
            continue;
        }
        int st = 0;
        while(cs[st] == 0) {
            st ++;
        }
        int idx = cs[st];
        for(int i = st; i < idx; i ++) {
            res[i] = 1;
        }
        for(int i = st+1; i < n; i ++) {
            int dif = cs[i] - (i*res[i]) - (idx-i);

            for(int j = 1; j < dif; j ++) {
                idx ++;
                if(idx >= n) { break; }
                res[idx] = 1;
            }
            if(idx == n) { break; }
            idx ++;
            if(idx == n) { break; }
        }
        for(int r : res) {
            cout << r << " ";
        }
        cout << "\n";
    }
    return 0;
}