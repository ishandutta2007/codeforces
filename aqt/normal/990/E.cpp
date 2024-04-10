#include <bits/stdc++.h>

using namespace std;

int N, M, K;
bool tkn[1000005];
int lst[1000005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    for(int i = 1; i<=M; i++){
        int n;
        cin >> n;
        tkn[n] = 1;
    }
    if(tkn[0]){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 1; i<=N; i++){
        if(tkn[i]){
            lst[i] = lst[i-1];
        }
        else{
            lst[i] = i;
        }
    }
    long long ans = LLONG_MAX;
    for(int k = 1; k<=K; k++){
        long long c;
        cin >> c;
        long long v = c;
        int crnt = k;
        while(crnt < N){
            if(crnt - lst[crnt] >= k){
                v = LLONG_MAX;
                break;
            }
            crnt = lst[crnt];
            v += c;
            crnt += k;
        }
        ans = min(v, ans);
    }
    if(ans == LLONG_MAX){
        ans = -1;
    }
    cout << ans << endl;
}