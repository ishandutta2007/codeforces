#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    scanf("%d", &n);
    printf("9");
    int num = 8;
    for(int i = 0; i < n - 1; i++){
        printf("%d", num);
        num++;
        if(num == 10) num = 0;
    }
    printf("\n");
    
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    
}