#include <bits/stdc++.h>

using namespace std;

int N;
map<pair<long long, long long>, long long> mp;
pair<long long, long long> arr[2005];

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i].first >> arr[i].second;
        for(int j = 1; j<i; j++){
            mp[{arr[i].first+arr[j].first, arr[i].second+arr[j].second}]++;
        }
    }
    long long ans = 0;
    for(auto p : mp){
        ans += p.second*(p.second-1)/2;
    }
    cout << ans;
}