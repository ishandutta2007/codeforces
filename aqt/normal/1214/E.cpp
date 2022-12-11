#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> ans;
int dep[200005];
int nd[200005];
pair<int, int> arr[200005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i =1; i<=N; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr+1, arr+1+N, greater<pair<int, int>>());
    for(int i= 1; i<=N; i++){
        dep[2*arr[i].second] = i;
        nd[i] = 2*arr[i].second;
        if(i-1){
            ans.push_back({2*arr[i-1].second, 2*arr[i].second});
        }
    }
    for(int i = 1; i<=N; i++){
        int idx = arr[i].second, d = arr[i].first;
        ans.push_back({idx*2-1, nd[dep[idx*2]+d-1]});
        dep[idx*2-1] = dep[idx*2]+d;
        if(!nd[dep[idx*2-1]]){
            nd[dep[idx*2-1]] = idx*2-1;
        }
    }
    for(auto p : ans){
        cout << p.first << " " << p.second << endl;
    }
}