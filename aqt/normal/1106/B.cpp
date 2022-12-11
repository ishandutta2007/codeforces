#include <bits/stdc++.h>

using namespace std;

int N, M;
long long amt[100005], cst[100005];
pair<int, int> arr[100005];
long long cnt = 0;

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 1; i<=N; i++){
        scanf("%d", &amt[i]);
    }
    for(int i = 1; i<=N; i++){
        scanf("%d", &cst[i]);
        arr[i] = {cst[i], i};
        cnt += amt[i];
    }
    sort(arr+1, arr+1+N);
    int idx = 1;
    for(int i = 1; i<=M; i++){
        int n, t;
        scanf("%d %d", &t, &n);
        if(n > cnt){
            printf("%d\n", 0);
            cnt = 0;
            continue;
        }
        long long tempn = n;
        long long ans = 0;
        ans += min(amt[t], tempn)*cst[t];
        n -= min(amt[t], tempn);
        cnt -= min(amt[t], tempn);
        amt[t] -= min(amt[t], tempn);
        while(n > 0){
            tempn = n;
            ans += min(amt[arr[idx].second], tempn)*cst[arr[idx].second];
            n -= min(amt[arr[idx].second], tempn);
            cnt -= min(amt[arr[idx].second], tempn);
            amt[arr[idx].second] -= min(amt[arr[idx].second], tempn);
            if(amt[arr[idx].second] == 0){
                idx++;
            }
        }
        printf("%lld\n", ans);
    }
}