#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int c[n];
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        c[i]--;
    }
    int k[n];
    vector<int> a[n];
    vector<int> b[n];
    for(int i = 0; i < n; i++) {
        cin >> k[i];
        a[i].resize(k[i]);
        for(int j = 0; j < k[i]; j++) {
            cin >> a[i][j];
            a[i][j]--;
            b[a[i][j]].push_back(i);
        }
    }
    int ans = 10000;
    for(int z = 0; z < 3; z++) {
        int cur = z;     
        vector<int> achieved[3];
        int deg[n];
        for(int i = 0; i < n; i++) {
            deg[i] = a[i].size();
            if(deg[i] == 0) {
                achieved[c[i]].push_back(i);
            }
        }
        int used[n] = {0};
        int cans = 0;
        while(count(used, used + n, 1) != n) {
            while(true) {
                vector<int> to_add;
                for(auto it: achieved[cur]) {
                    used[it] = 1;
                    for(auto jt: b[it]) {
                        deg[jt]--;
                        if(deg[jt] == 0) {
                            to_add.push_back(jt);
                        }
                    }
                }
                achieved[cur].clear();
                for(auto it: to_add) {
                    achieved[c[it]].push_back(it);
                }
                if(to_add.empty()) {
                    break;
                }
            }
            cur = (cur + 1) % 3;
            cans++;
        }
        ans = min(ans, cans + n - 1);
    }
    cout << ans << endl;
    return 0;
}