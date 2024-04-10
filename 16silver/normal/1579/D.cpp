#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        if(tmp) pq.emplace(tmp, i+1);
    }
    vector<pair<int,int>> ans;
    while(pq.size()>1){
        auto x = pq.top(); pq.pop();
        auto y = pq.top(); pq.pop();
        ans.emplace_back(x.second, y.second);
        if(x.first>1) pq.emplace(x.first-1, x.second);
        if(y.first>1) pq.emplace(y.first-1, y.second);
    }
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x.first << " " << x.second << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for(int i=0;i<T;i++) solve();
}