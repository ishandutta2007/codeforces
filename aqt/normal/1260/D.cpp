#include <bits/stdc++.h>

using namespace std;

int N, M, K, T, A = 200000;
int arr[200005];
int but[200005], cord[200005], d[200005];
int dif[200005];

long long solve(int n){
    long long ret = 0;
    for(int i = 1; i<=K; i++){
        if(n < d[i]){
            dif[cord[i]]++;
            dif[but[i]+1]--;
        }
    }
    for(int i = 1; i<=N+1; i++){
        dif[i] += dif[i-1];
        ret += !!dif[i];
    }
    for(int i = 1; i<=N+1; i++){
        dif[i] = 0;
    }
    return 2*ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N >> K >> T;
    T -= N+1;
    for(int i = 1; i<=M; i++){
        cin >> arr[i];
    }
    for(int i = 1; i<=K; i++){
        cin >> cord[i] >> but[i] >> d[i];
    }
    int l = 1, r = A, ans = A+1;
    while(l <= r){
        int mid = l+r>>1;
        if(solve(mid) <= T){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    int cnt = 0;
    for(int i = 1; i<=M; i++){
        cnt += arr[i] >= ans;
    }
    cout << cnt << "\n";
}