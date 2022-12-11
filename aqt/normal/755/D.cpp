#include <bits/stdc++.h>

using namespace std;

int N, K;
int BIT[1000005];

void upd(int p, int v){
    for(int i = p; i<=N; i+=i&-i){
        BIT[i] += v;
    }
}

int query(int p){
    int ret = 0;
    for(int i = p; i; i-=i&-i){
        ret += BIT[i];
    }
    return ret;
}

int main(){
    cin >> N >> K;
    K = min(N-K, K);
    int crnt = 1;
    long long tot = 1;
    for(int k = 1; k<=N; k++){
        tot++;
        int nxt = crnt+K;
        if(nxt > N){
            nxt = nxt-N;
            tot += query(nxt-1);
            tot += query(N) - query(crnt);
        }
        else{
            tot += query(nxt-1);
            tot -= query(crnt);
        }
        upd(crnt, 1);
        upd(nxt, 1);
        crnt = nxt;
        cout << tot << " ";
    }
}