#include <bits/stdc++.h>

using namespace std;

int N;
long long K;
long long arr[105];
vector<long long> v;

int main(){
    cin >> N >> K;
    for(int i= 1; i<=N; i++){
        cin >> arr[i];
        long long n = arr[i];
        for(long long j = 1; j*j<=n; j++){
            v.push_back(j);
            v.push_back(n/j);
        }
    }
    v.push_back(1000000000000LL);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    long long ans = 1;
    for(int i = 0; i<v.size()-1; i++){
        long long l = v[i], r = v[i+1]-1;
        while(l <= r){
            long long mid = l+r>>1;
            long long tot = 0;
            for(int k = 1; k<=N; k++){
                tot += (arr[k]+mid-1)/mid*mid-arr[k];
            }
            if(tot <= K){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
    }
    cout << ans << endl;
}