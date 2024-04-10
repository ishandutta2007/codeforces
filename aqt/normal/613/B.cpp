#include <bits/stdc++.h>

using namespace std;

long long N, A, X, Y, K;
pair<long long, int> arr[100005];
long long srt[100005];
long long pre[100005];
int out[100005];
long long org[100005];

long long chk(long long mid, int i){
    int idx = lower_bound(srt+1, srt+1+N-i, mid) - srt;
    return mid*(idx-1) - pre[idx-1];
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> A >> X >> Y >> K;
    for(int i = 1; i<=N; i++){
        cin >> arr[i].first;
        srt[i] = arr[i].first;
        arr[i].second = i;
        org[i] = arr[i].first;
    }
    sort(arr+1, arr+1+N, greater<pair<long long, int>>());
    sort(srt+1, srt+1+N);
    partial_sum(srt+1, srt+1+N, pre+1);
    long long ans = 0;
    int best = 0, crnt = 0;
    for(int i = 0; i<=N; i++){
        if(i){
            K -= A - arr[i].first;
        }
        if(K < 0){
            break;
        }
        long long l = 1, r = A, temp = 0;
        while(l <= r){
            long long mid = l + r >> 1;
            if(chk(mid, i) <= K){
                l = mid + 1;
                temp = mid;
            }
            else{
                r = mid - 1;
            }
        }
        if(ans < temp*Y+i*X){
            ans = max(ans, temp*Y + i*X);
            best = i;
            crnt = temp;
        }
    }
    for(int i = 1; i<=best; i++){
        out[arr[i].second] = A;
    }
    for(int i= 1; i<=N; i++){
        if(!out[i]){
            out[i] = max(1LL*crnt, org[i]);
        }
    }
    cout << ans << "\n";
    for(int i = 1; i<=N; i++){
        cout << out[i] << " ";
    }
}