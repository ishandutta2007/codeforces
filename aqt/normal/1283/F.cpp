#include <bits/stdc++.h>

using namespace std;

int N;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int cld[200005];
int mx[200005];
int arr[200005];
vector<pair<int, int>> ans;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        mx[i] = i;
        if(i-N){
            cin >> arr[i];
            cld[arr[i]]++;
        }
    }
    for(int i = 1; i<=N; i++){
        if(!cld[i]){
            pq.push({mx[i], i});
        }
    }
    for(int i = N-1; i; i--){
        if(pq.empty()){
            cout << -1 << endl;
            return 0;
        }
        auto p = pq.top();
        pq.pop();
        ans.push_back({arr[i], p.second});
        mx[arr[i]] = max(mx[arr[i]], p.first);
        cld[arr[i]]--;
        if(!cld[arr[i]]){
            pq.push({mx[arr[i]], arr[i]});
        }
    }
    cout << pq.top().second << "\n";
    reverse(ans.begin(), ans.end());
    for(auto p : ans){
        cout << p.first << " " << p.second << "\n";
    }
}