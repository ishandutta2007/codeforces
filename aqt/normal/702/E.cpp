#include <bits/stdc++.h>

using namespace std;

int N;
long long K;
long long par[100005][40], sum[100005][40], mini[100005][40];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for(int i = 1; i<=N; i++){
        cin >> par[i][0];
        par[i][0]++;
    }
    for(int i = 1; i<=N; i++){
        cin >> sum[i][0];
        mini[i][0] = sum[i][0];
    }
    for(int d = 1; d<40; d++){
        for(int i= 1; i<=N; i++){
            par[i][d] = par[par[i][d-1]][d-1];
        }
    }
    for(int d = 1; d<40; d++){
        for(int i = 1; i<=N; i++){
            sum[i][d] = sum[i][d-1] + sum[par[i][d-1]][d-1];
            mini[i][d] = min(mini[i][d-1], mini[par[i][d-1]][d-1]);
        }
    }
    for(int i = 1; i<=N; i++){
        long long s = 0, m = LLONG_MAX;
        int c = i;
        for(int d = 39; d>=0; d--){
            if((1LL<<d)&K){
                s += sum[c][d];
                m = min(m, mini[c][d]);
                c = par[c][d];
            }
        }
        cout << s << " " << m << "\n";
    }
}