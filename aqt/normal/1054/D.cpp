#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[200005];
map<int, int> mp;

int main(){
    cin >> N >> K;
    int M = (1<<K)-1;
    mp[0] = 1;
    for(int i =1; i<=N; i++){
        cin >> arr[i];
        arr[i] ^= arr[i-1];
        if(mp[arr[i]] < mp[arr[i]^M]){
            mp[arr[i]]++;
        }
        else{
            mp[arr[i]^M]++;
        }
    }
    long long ans = 1LL*N*(N+1)/2;
    for(auto p : mp){
        ans -= 1LL*(p.second)*(p.second-1)/2;
    }
    cout << ans << endl;
}