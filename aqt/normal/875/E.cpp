#include <bits/stdc++.h>

using namespace std;

int N, s1, s2;
int arr[100005];
int mn[17][100005], mx[17][100005];

int getpos(int p, int n, int t){
    int l = n+1, r = N, ret = n;
    while(l <= r){
        int mid = l+r>>1;
        int k = 31-__builtin_clz(mid-n-1);
        int maxi = max(mx[k][n+1], mx[k][mid-(1<<k)+1]);
        int mini = min(mn[k][n+1], mn[k][mid-(1<<k)+1]);
        if(abs(maxi-p) <= t && abs(mini-p) <= t){
            ret = mid;
            l = mid+1;
        }
        else{
            r = mid -1;
        }
    }
    return ret;
}

bool solve(int t){
    int M = getpos(s2, 0, t);
    for(int i = 1; i<=M; i++){
        M = max(getpos(arr[i], i, t), M);
    }
    if(M == N){
        return 1;
    }
    M = getpos(s1, 0, t);
    for(int i = 1; i<=M; i++){
        M = max(getpos(arr[i], i, t), M);
    }
    return (M == N);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> s1 >> s2;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        mn[0][i] = mx[0][i] = arr[i];
    }
    for(int d = 1; d<17; d++){
        for(int i = 1; i<=N-(1<<d)+1; i++){
            mn[d][i] = min(mn[d-1][i], mn[d-1][i+(1<<(d-1))]);
            mx[d][i] = max(mx[d-1][i], mx[d-1][i+(1<<(d-1))]);
        }
    }
    int l = abs(s2-s1), r = 1000000000, ans = r;
    while(l <= r){
        int mid = l+r>>1;
        if(solve(mid)){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << ans << endl;
}