#include <bits/stdc++.h>

using namespace std;

int N, M;
pair<int, pair<int, int>> arr[200005];
bool pos[200005];
int par[200005];

int getrt(int n){
    return par[n] = (par[n] == n ? n : getrt(par[n]));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i<=N; i++){
        par[i] = i;
    }
    for(int i = 1; i<=M; i++){
        cin >> arr[i].second.first >> arr[i].second.second >> arr[i].first;
    }
    sort(arr+1, arr+1+M);
    int ans = 0;
    for(int i = 1; i<=M; ){
        int crnt = arr[i].first;
        int j = i;
        while(j <= M && arr[j].first == crnt){
            if(getrt(arr[j].second.first) != getrt(arr[j].second.second)){
                pos[j] = 1;
            }
            j++;
        }
        while(i < j){
            if(getrt(arr[i].second.first) != getrt(arr[i].second.second)){
                par[getrt(arr[i].second.first)] = getrt(arr[i].second.second);
            }
            else if(pos[i]){
                ans++;
            }
            i++;
        }
    }
    cout << ans << endl;
}