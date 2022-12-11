#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> arr[1005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr+1, arr+1+N, greater<pair<int, int>>());
    long long ans = 0;
    for(int i = 1; i<=N; i++){
        ans += arr[i].first*(i-1)+1;
    }
    cout << ans << "\n";
    for(int i =1; i<=N; i++){
        cout << arr[i].second << " ";
    }
}