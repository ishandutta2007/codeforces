#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100005];
vector<int> cmp;
bool vis[100005];
vector<vector<int>> ans;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        cmp.push_back(arr[i]);
    }
    sort(cmp.begin(), cmp.end());
    for(int i =1 ; i<=N; i++){
        arr[i] = lower_bound(cmp.begin(), cmp.end(), arr[i]) - cmp.begin() + 1;
    }
    for(int i = 1; i<=N; i++){
        if(!vis[i]){
            int n = arr[i];
            vis[i] = 1;
            vector<int> v;
            v.push_back(i);
            while(!vis[n]){
                vis[n] = 1;
                v.push_back(n);
                n = arr[n];
            }
            ans.push_back(v);
        }
    }
    cout << ans.size() << "\n";
    for(vector<int> v: ans){
        cout << v.size() << " ";
        for(int n : v){
            cout << n << " ";
        }
        cout << "\n";
    }
}