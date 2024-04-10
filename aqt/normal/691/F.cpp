#include <bits/stdc++.h>

using namespace std;

int N, M = 3000000, Q;
long long fre[3000005];
long long pre[3000005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        fre[n]++;
    }
    for(int i = 1; i<=M; i++){
        for(int j = i; j<=M; j+=i){
            if(i*i == j){
                pre[j] += fre[i]*(fre[i]-1);
            }
            else{
                pre[j] += fre[i]*fre[j/i];
            }
        }
    }
    for(int i = 1; i<=M; i++){
        pre[i] += pre[i-1];
    }
    cin >> Q;
    while(Q--){
        int p;
        cin >> p;
        cout << 1LL*N*(N-1) - pre[p-1] << "\n";
    }
}