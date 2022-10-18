#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int r[n];
    map<int, int> cnt;
    set<pair<int, int>, greater<pair<int, int>>> que;
    for(int i = 0; i < n; i++) {
        cin >> r[i];
        que.erase({cnt[r[i]], r[i]});
        cnt[r[i]]++;
        que.insert({cnt[r[i]], r[i]});
    }
    vector<vector<int>> ans;
    while(que.size() >= 3) {
        auto it1 = *begin(que);
        auto it2 = *next(begin(que));
        auto it3 = *next(next(begin(que)));
        que.erase(it1);
        que.erase(it2);
        que.erase(it3);
        ans.push_back({it1.second, it2.second, it3.second});
        it1.first--, it2.first--, it3.first--;
        if(it1.first) que.insert(it1);
        if(it2.first) que.insert(it2);
        if(it3.first) que.insert(it3);
        
    }
    cout << ans.size() << endl;
    for(auto it: ans) {
        sort(begin(it), end(it), greater<int>());
        for(auto jt: it) {
            cout << jt << ' ';
        }
        cout << endl;
    }
}