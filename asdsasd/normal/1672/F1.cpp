#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> cnt(n + 1);
    vector<vector<int>> vec(n, vector<int>());
    for(int i = 0; i < n; i++){
        cin >> A[i];
        vec[cnt[A[i]]].push_back(i);
        cnt[A[i]]++;
    }
    vector<int> ans(n);
    for(auto ls: vec){
        if(ls.empty()) continue;
        int l = ls.size();
        vector<pair<long long, int>> pa;
        for(auto l: ls){
            pa.push_back({(long long) cnt[A[l]] * (long long) n + A[l], l});
        }
        sort(pa.begin(), pa.end());
        for(int i = 0; i < l; i++){
            int j;
            if(i == 0) j = l - 1;
            else j = i - 1;
            ans[pa[j].second] = A[pa[i].second];
        }
    }
    for(int i = 0; i < n; i++){
        cout << ans[i];
        if(i == n - 1) cout << "\n";
        else cout << " ";
    }
}

int main(void){
    int t;
    cin >> t;
    while(t--) solve();
    
}