#include <bits/stdc++.h>

using namespace std;

int nxt[1000000][2];
int dep[1000000];
int cnt = 1;
int sz[1000000];

void upd(int n, int v){
    if(dep[n] == -1){
        sz[n] = 1;
        return;
    }
    if(!nxt[n][(v>>dep[n])&1]){
        nxt[n][(v>>dep[n])&1] = ++cnt;
        dep[cnt] = dep[n] - 1;
    }
    upd(nxt[n][(v>>dep[n])&1], v);
    sz[n] = 0;
    if(nxt[n][0]){
        sz[n] += sz[nxt[n][0]];
    }
    if(nxt[n][1]){
        sz[n] += sz[nxt[n][1]];
    }
}

int mex(int n, int v){
    if(dep[n] == -1 || !n){
        return 0;
    }
    int b = v&(1<<dep[n]);
    //cout << " " << n << " " << dep[n] << "\n";
    if(sz[nxt[n][!!b]] == (1<<(dep[n]))){
        //cout << "   " << dep[n] << "\n";
        return (1<<(dep[n])) + mex(nxt[n][!b], v);
    }
    else{
        return mex(nxt[n][!!b], v);
    }
}

int main(){
    int N, Q, X = 0;
    cin >> N >> Q;
    dep[1] = 19;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        upd(1, n);
    }
    while(Q--){
        int x;
        cin >> x;
        X ^= x;
        cout << mex(1, X) << "\n";
    }
}