#include <bits/stdc++.h>

using namespace std;

int T, N, K, D;
int fre[1000005];
int arr[1000005];
int cnt = 0;

void upd(int n, int v){
    fre[n]+=v;
    if(fre[n] == 1 && v == 1){
        cnt++;
    }
    else if(fre[n] == 0 && v == -1){
        cnt--;
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        cin >> N >> K >> D;
        swap(K, D);
        for(int i = 1; i<=N; i++){
            cin >> arr[i];
        }
        cnt = 0;
        int ans = K;
        for(int i = 1; i<K; i++){
            upd(arr[i], 1);
        }
        for(int i = K; i<=N; i++){
            upd(arr[i], 1);
            ans = min(ans, cnt);
            upd(arr[i-K+1], -1);
        }
        for(int i = N-K+2; i<=N; i++){
            upd(arr[i], -1);
        }
        cout << ans << "\n";
    }
}