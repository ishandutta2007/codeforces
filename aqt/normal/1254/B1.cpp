#include <bits/stdc++.h>

using namespace std;

int N;
long long pre[1000005];

long long solve(long long k){
    long long ret = 0;
    for(int i = 1; i<=N; i++){
        ret += min(pre[i]%k, k-pre[i]%k);
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> pre[i];
        pre[i] += pre[i-1];
    }
    long long t = pre[N];
    long long ans = LLONG_MAX;
    for(long long k = 2; k<=sqrt(t); k++){
        if(t%k == 0){
            ans = min(ans, solve(k));
            while(t%k == 0){
                t /= k;
            }
        }
    }
    if(t > 1){
        ans = min(ans, solve(t));
    }
    if(ans == LLONG_MAX){
        ans = -1;
    }
    cout << ans << endl;
}