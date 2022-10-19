#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    scanf("%d %d", &n, &k);
    int x = 0, ret;
    for(int i = 0; i < n; i++){
        printf("%d\n", x ^ i);
        fflush(stdout);
        scanf("%d", &ret);
        if(ret == 1) return;
        x = i;
    }
    return;
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    
}