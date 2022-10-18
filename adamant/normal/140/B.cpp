#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1);
    for(int i = 0; i <= n; i++) {
        a[i].resize(n);
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    for(int i = 0; i < n; i++) {
        int best_score = n, ans = 0; 
        for(int j = 0; j < n; j++) {
            int cur = 0;
            bool chosen = false;
            for(int k = 0; k < n; k++) {
                if(a[n][k] <= j && a[n][k] != i) {
                    cur = a[n][k];
                    chosen = true;
                    break;
                }
            }
            if(!chosen) {
                continue;
            }
            int score = 0;
            for(int k = 0; k < n; k++) {
                if(a[i][k] == cur) {
                    score = k;
                    break;
                }
            }
            if(score < best_score) {
                ans = j;
                best_score = score;
            }
        }
        //cout << best_score << ' ' << ans + 1 << endl;
        
        cout << ans + 1 << ' ';
    }
}