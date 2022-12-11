#include <bits/stdc++.h>

using namespace std;

int N;
bool tkn[100005];
pair<pair<int, int>, pair<int, int>> arr[100005];
priority_queue<pair<int, int>> mnn, mxx;

bool solve(){
    bool ret = 1;
    vector<pair<int, int>> v;
    fill(tkn+1, tkn+1+N, 0);
    while(mnn.size()){
        mnn.pop();
    }
    while(mxx.size()){
        mxx.pop();
    }
    for(int i = 1; i<=N; i++){
        v.push_back({arr[i].first.first, i});
        v.push_back({arr[i].first.second+1, -i});
    }
    sort(v.begin(), v.end());
    int idx = 0;
    while(idx < v.size()){
        int crnt = v[idx].first;
        while(idx < v.size() && crnt == v[idx].first){
            if(v[idx].second < 0){
                tkn[abs(v[idx].second)] = 0;
            }
            else{
                tkn[v[idx].second] = 1;
                int t = v[idx].second;
                mnn.push({-arr[t].second.second, t});
                mxx.push({arr[t].second.first, t});
            }
            idx++;
        }
        while(mnn.size() && !tkn[mnn.top().second]){
            mnn.pop();
        }
        while(mxx.size() && !tkn[mxx.top().second]){
            mxx.pop();
        }
        if(mnn.size() && -mnn.top().first < mxx.top().first){
            return 0;
        }
    }
    return 1;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i].first.first >> arr[i].first.second;
        cin >> arr[i].second.first >> arr[i].second.second;
    }
    bool ans = solve();
    for(int i = 1; i<=N; i++){
        swap(arr[i].first, arr[i].second);
    }
    ans &= solve();
    if(ans){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}