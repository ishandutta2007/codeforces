#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<pair<int, int>> v;
    int N, K;
    cin >> N >> K;
    for(int i =1; i<=N; i++){
        int n;
        cin >> n;
        v.push_back({n,i});
    }
    vector<pair<int, int>> ans;
    while(K--){
        sort(v.begin(), v.end());
        if(v[0].first == v[N-1].first){
            break;
        }
        v[N-1].first--;
        v[0].first++;
        ans.push_back({v[N-1].second, v[0].second});
    }
    sort(v.begin(), v.end());
    cout << v[N-1].first-v[0].first << " " << ans.size() << endl;
    for(auto p : ans){
        cout << p.first << " " << p.second << endl;
    }
}