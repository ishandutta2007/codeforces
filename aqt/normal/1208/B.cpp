#include <bits/stdc++.h>

using namespace std;

int N;
int arr[2005];
map<int, int> mp;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int cnt = 0;
    for(int i= 1; i<=N; i++){
        cin >> arr[i];
        mp[arr[i]]++;
        if(mp[arr[i]] == 2){
            cnt++;
        }
    }
    int ans = N;
    if(!cnt){
        ans = 0;
    }
    for(int i = 1; i<=N; i++){
        for(int j = i; j<=N; j++){
            mp[arr[j]]--;
            if(mp[arr[j]] == 1){
                cnt--;
            }
            if(cnt == 0){
                ans = min(ans, j-i+1);
            }
        }
        for(int j =i; j<=N; j++){
            mp[arr[j]]++;
            if(mp[arr[j]] == 2){
                cnt++;
            }
        }
    }
    cout << ans << endl;
}