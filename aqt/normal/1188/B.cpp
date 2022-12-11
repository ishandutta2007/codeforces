#include <bits/stdc++.h>

using namespace std;

long long N, P, K;
unordered_map<long long, long long> mp;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long ans = 0;
    cin >> N >> P >> K;
    while(N--){
        long long n;
        cin >> n;
        long long k = K*n%P;
        n = n*n%P;
        n = n*n%P;
        n = ((n-k)%P+P)%P;
        mp[n]++;
    }
    for(auto p : mp){
        ans += p.second*(p.second-1)/2;
    }
    cout << ans << endl;
}