#include <bits/stdc++.h>
using namespace std;

long long dp[202000];

void solve(){
    int n, h, w;
    cin >> n;
    vector<pair<int, pair<int, int>>> cand(2 * n);
    vector<pair<int, pair<int, int>>> hw(n);
    for(int i = 0; i < n; i++){
        cin >> h >> w;
        hw[i] = make_pair(h, make_pair(w, i));
        cand[2 * i] = make_pair(h, make_pair(w, i + 1));
        cand[2 * i + 1] = make_pair(w, make_pair(h, i + 1));
    }
    sort(hw.begin(), hw.end());
    sort(cand.begin(), cand.end());
    vector<int> ans(n);
    for(int i = 0; i < n; i++) ans[i] = -1;
    int ind = -1;
    int min_ = 1e9;
    int pos = 0;
    for(int i = 0; i < n; i++){
        int h = hw[i].first;
        int w = hw[i].second.first;
        int j = hw[i].second.second;
        while(cand[pos].first < h){
            if (cand[pos].second.first < min_){
                min_ = cand[pos].second.first;
                ind = cand[pos].second.second;
            }
            pos++;
        }
        if (min_ < w){
            ans[j] = ind;
        }
    }
    for(auto a:ans) cout << a << " ";
    cout << endl;
}

int main(void){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}