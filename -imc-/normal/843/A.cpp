#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<int> key = a;
    sort(all(key));
    
    for (int i = 0; i < n; i++)
        a[i] = lower_bound(all(key), a[i]) - key.begin();
    
    vector<vector<int>> ans;
    vector<char> used(n);
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            int now = i;
            
            vector<int> p;
            while (!used[now]) {
                used[now] = true;
                now = a[now];
                p.push_back(now);
            }
            sort(all(p));
            ans.push_back(p);
        }
    }
    
    cout << ans.size() << "\n";
    for (auto& v: ans) {
        cout << v.size() << " ";
        for (int x: v) cout << x + 1 << " ";
        cout << "\n";
    }
    
    return 0;
}