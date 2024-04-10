#include <bits/stdc++.h>

using namespace std;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int m = 1 << k;
    int cnt[m] = {0};
    for(int i = 0; i < n; i++) {
        int mask = 0;
        for(int j = 0; j < k; j++) {
            int t;
            cin >> t;
            mask = 2 * mask + t;
        }
        cnt[mask]++;
    }
    int mask_sz = 1 << m;
    for(int mask = 1; mask < mask_sz; mask++) {
        int score[k] = {0};
        for(int i = 0; i < m; i++) {
            if((mask >> i) & 1) {
                if(cnt[i] == 0) {
                    score[0] = -1000;
                }
                for(int j = 0; j < k; j++) {
                    if((i >> j) & 1) {
                        score[j]--;
                    } else {
                        score[j]++;
                    }
                }
            }
        }
        int non_neg = 0;
        for(int i = 0; i < k; i++) {
            non_neg += score[i] >= 0;
        }
        if(non_neg == k) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    
}