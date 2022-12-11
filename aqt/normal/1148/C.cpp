#include <bits/stdc++.h>

using namespace std;

int N;
int arr[300005], pos[300005];
vector<pair<int ,int>> ans;

void turn(int x, int y){
    swap(pos[x], pos[y]);
    arr[pos[x]] = x;
    arr[pos[y]] = y;
    ans.push_back({pos[y], pos[x]});
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i =1 ; i<=N; i++){
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    for(int n = 2; n<=N/2; n++){
        if(pos[n] > N/2){
            turn(n, arr[1]);
            turn(arr[1], arr[N]);
            turn(arr[n], n);
        }
        else{
            turn(n, arr[N]);
            turn(arr[n], n);
        }
    }
    for(int n = N/2+1; n<=N-1; n++){
        if(pos[n] <= N/2){
            turn(n, arr[N]);
            turn(arr[1], arr[N]);
            turn(arr[n], n);
        }
        else{
            turn(n, arr[1]);
            turn(arr[n], n);
        }
    }
    if(arr[1] != 1){
        turn(arr[1], arr[N]);
    }
    cout << ans.size() << "\n";
    for(auto p : ans){
        cout << p.first << " " << p.second << "\n";
    }
}