#include <bits/stdc++.h>

using namespace std;

int N, K, X, M;
int lst[105], cnt[105];
pair<pair<int, int>, int> ord[105];
int ans[105];

int main(){
    cin >> N >> K >> X >> M;
    for(int i = 1; i<=M; i++){
        int n;
        cin >> n;
        lst[n] = i;
        cnt[n]++;
    }
    X -= M;
    for(int i =1; i<=N; i++){
        ord[i] = {{cnt[i], -lst[i]}, i};
    }
    sort(ord+1, ord+1+N, greater<pair<pair<int, int>, int>>());
    for(int n=1 ; n<=N; n++){
        if(n <= K){
            if(ord[n].first.first == 0){
                if(!X){
                    ans[ord[n].second] = 3;
                }
                else{
                    ans[ord[n].second] = 2;
                }
                continue;
            }
            int T = X, cnt = 0;
            for(int k = n+1; k<=N && T >= 0; k++){
                if(T - (ord[n].first.first+1-ord[k].first.first) >= 0){
                    T -= (ord[n].first.first+1-ord[k].first.first);
                    cnt++;
                }
                else{
                    break;
                }
            }
            if(cnt > K-n){
                ans[ord[n].second] = 2;
            }
            else{
                ans[ord[n].second] = 1;
            }
        }
        else if(ord[n].first.first+X > ord[K].first.first){
            ans[ord[n].second] = 2;
        }
        else{
            ans[ord[n].second] = 3;
        }
    }
    for(int i= 1; i<=N; i++){
        cout << ans[i] << " ";
    }
}