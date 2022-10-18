#include<bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t

signed main(){
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    vector<int> lol[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        lol[a[i]].push_back(i);
    }
    int split[n];
    bool ok = true;
    for(int i = 0; i < n; i++) {
        if(lol[i].size()) {
            split[i] = n - i;
            ok &= (lol[i].size() % split[i]) == 0;
        }
    }
    if(!ok) {
        cout << "Impossible" << endl;
    } else {
        cout << "Possible" << endl;
        int ans[n];
        int cur = 1;
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            if(lol[i].size()) {
                for(auto it: lol[i]) {
                    ans[it] = cur;
                    cnt++;
                    if(cnt % split[i] == 0) {
                        cur++;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}