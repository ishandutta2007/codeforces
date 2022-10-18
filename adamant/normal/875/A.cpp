#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int get_sum(int x) {
    int ans = 0;
    while(x) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> ans;
    
    for(int i = 90; i >= 1; i--) {
        if(n - i > 0 && get_sum(n - i) == i) {
            ans.push_back(n - i);
        }
    }
    cout << ans.size() << endl;
    for(auto it: ans) cout << it << ' ';
    return 0;
}