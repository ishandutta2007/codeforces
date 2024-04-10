#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    for(int i = 0; i < n; i++){
        char tmp = 'a' + i % b;
        printf("%c", tmp);
    }
    printf("\n");
}

int main(void){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        solve();
    }
    
}