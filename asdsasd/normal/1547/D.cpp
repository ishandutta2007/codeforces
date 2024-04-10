#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    scanf("%d", &n);
    vector<int> X(n);
    for(int i = 0; i < n; i++) scanf("%d", &X[i]);
    vector<int> Y(n);
    int x = 0;
    for(int i = 0; i < n; i++){
        int y = 0;
        for(int j = 0; j < 30; j++){
            if((x >> j & 1) && not (X[i] >> j & 1)){
                y += 1 << j;
            }
        }
        Y[i] = y;
        x = y ^ X[i];
    }
    for(int i = 0; i < n; i++){
        printf("%d", Y[i]);
        if(i == n - 1) printf("\n");
        else printf(" ");
    }
    
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--) solve();
}