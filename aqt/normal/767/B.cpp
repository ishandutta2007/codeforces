#include <bits/stdc++.h>

using namespace std;

long long N, S, E, T;
long long arr[100005];

int main(){
    scanf("%lld %lld %lld %lld", &S, &E, &T, &N);
    long long ans = 0, ansval = S, nxt = S;
    for(int i = 1; i<=N; i++){
        scanf("%lld", &arr[i]);
    }
    long long mini = arr[1];
    for(int i = 1; i<=N; i++){
        mini = min(mini, arr[i]);
    }
    if(mini > S){
        ans = S;
        ansval = 0;
    }
    for(int i = 1; i<=N; ){
        int idx = i;
        if(nxt-arr[idx]+1 < ansval && max(nxt, arr[idx]-1)+T <= E){
            ansval = nxt-arr[idx]+1;
            ans = arr[idx]-1;
        }
        while(arr[idx] == arr[i]){
            nxt = max(nxt+T, arr[idx]+T);
            idx++;
        }
        if(nxt + T > E){
            break;
        }
        i = idx;
    }
    if(nxt + T <= E){
        ans = nxt;
    }
    cout << ans << endl;
}