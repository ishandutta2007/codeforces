#include <bits/stdc++.h>
using namespace std;

int ans[1010];

int main(void){
    int t;
    scanf("%d", &t);
    int x = 0;
    for(int i = 0; i < 1000; i++){
        x++;
        while(x % 3 == 0 || x % 10 == 3) x++;
        ans[i] = x;
    }
    while(t--){
        int k;
        scanf("%d", &k);
        printf("%d\n", ans[k - 1]);
        
    }
    
}