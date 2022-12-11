#include <bits/stdc++.h>

using namespace std;

int N;
long long arr[100005];
int qu[100005];
long long ans[100005];
int par[100005];
long long sum[100005];
bool tkn[100005];

int getrt(int n){
    return par[n] = (par[n] == n ? n : getrt(par[n]));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        par[i] = i;
    }
    for(int i = 1; i<=N; i++){
        cin >> qu[i];
    }
    tkn[0] = tkn[N+1] = 1;
    par[N+1] = N+1;
    long long best = 0;
    for(int i = N; i; i--){
        ans[i] = best;
        int n = qu[i];
        sum[n] = arr[n];
        tkn[n] = 1;
        if(tkn[n+1]){
            sum[n] += sum[getrt(n+1)];
            par[getrt(n+1)] = n;
        }
        if(tkn[n-1]){
            sum[n] += sum[getrt(n-1)];
            par[getrt(n-1)] = n;
        }
        best = max(best, sum[n]);
    }
    for(int i = 1; i<=N; i++){
        cout<< ans[i] << "\n";
    }
}