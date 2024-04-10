#include <bits/stdc++.h>

using namespace std;

int N;
int arr[500005];
int srt[500005];

int chk(int n){
    bool done = 0;
    long long s = 0, pre = 0;
    for(int i = 1; i<=N; i++){
        srt[i] = arr[i];
    }
    srt[N+1] = n;
    sort(srt+1, srt+2+N, greater<int>());
    for(int i = 1, j = N+2; i<=N+1; i++){
        if(srt[i] == n && !done){
            done = 1;
        }
        s += srt[i];
        while(j > i && srt[j-1] <= i){
            pre += srt[--j];
        }
        while(j <= i){
            pre -= srt[j++];
        }
        long long m = 1LL*(j-i-1)*i;
        if(m+pre+1LL*i*(i-1) < s){
            if(done){
                return 1;
            }
            else{
                return -1;
            }
        }
    }
    return 0;
}

int solve(int t){
    int l = 0, r = N, ans = -1;
    while(l <= r){
        int mid = l+r>>1;
        int ret = chk(mid);
        if(!ret){
            ret = t;
            ans = mid;
        }
        if(ret == 1){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return ans;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    long long s = 0;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        s += arr[i];
    }
    sort(arr+1, arr+1+N, greater<int>());
    int lb = solve(1);
    if(lb == -1){
        cout << -1;
        return 0;
    }
    int rb = solve(-1);
    if(lb%2 != s%2){
        lb++;
    }
    if(rb%2 != s%2){
        rb--;
    }
    if(lb > rb){
        cout << -1;
        return 0;
    }
    for(int i = lb; i<=rb; i+=2){
        cout << i << " ";
    }
}