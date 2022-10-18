#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 42;

int get(int x){
    if(x < 10) {
        return x;
    }
    int ans = 1;
    while(x != 0) {
        if(x % 10) {
            ans = (ans * (x % 10));
        }
        x /= 10;
    }
    return get(ans);
}
    vector<int> cnt[10];

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    for(int i = 1; i < maxn; i++) {
        cnt[get(i)].push_back(i);
    }
    while(q--){ 
        int l, r, k;
        cin >> l >> r >> k;
        cout << upper_bound(begin(cnt[k]), end(cnt[k]), r) - lower_bound(begin(cnt[k]), end(cnt[k]), l) << endl;
    }
    return 0;
}