#include <bits/stdc++.h>

using namespace std;

int N, M;
int dgr[1000005];
int par[1000005];
int cnt[1000005];

int getrt(int n){
    return par[n] = (par[n] == n ? n : getrt(par[n]));
}

int main(){
    cin >> N >> M;
    int C = N;
    dgr[1]+=2;
    for(int i = 1; i<=N; i++){
        par[i] = i;
    }
    for(int i=1; i<=M; i++){
        int a, b;
        cin >> a >> b;
        dgr[a]++;
        dgr[b]++;
        if(getrt(a) != getrt(b)){
            par[getrt(a)] = getrt(b);
            C--;
        }
    }
    for(int i = 1; i<=N; i++){
        if(dgr[i]&1){
            cnt[getrt(i)]++;
        }
        if(!dgr[i]){
            C--;
        }
    }
    int tot = 0;
    if(C > 1){
        tot = C;
        for(int i= 1; i<=N; i++){
            if(cnt[i] >= 2){
                cnt[i] -= 2;
            }
            tot += cnt[i]/2;
        }
    }
    else{
        for(int i = 1; i<=N; i++){
            tot += cnt[i]/2;
        }
    }
    cout << tot;
}