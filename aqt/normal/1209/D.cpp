#include <bits/stdc++.h>

using namespace std;

int N, K;
int par[100005];

int getrt(int n){
    return par[n] = (par[n] == n ? n : getrt(par[n]));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    swap(N, K);
    for(int i = 1; i<=K; i++){
        par[i] = i;
    }
    int ans = 0;
    for(int i = 1; i<=N; i++){
        int a, b;
        cin >> a >> b;
        if(getrt(a) != getrt(b)){
            par[getrt(a)] = getrt(b);
            ans++;
        }
    }
    cout << N-ans << endl;
}