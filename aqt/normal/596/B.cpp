#include <bits/stdc++.h>

using namespace std;

int N;
long long arr[200005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    long long ans = 0;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        ans += abs(arr[i]-arr[i-1]);
    }
    cout << ans << endl;
}