#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    scanf("%d", &n);
    int odd = 0;
    int even = 0;
    int a;
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        if(i % 2 == a % 2) continue;
        if(i % 2 == 0) odd++;
        else even++;
    }
    if(odd == even) printf("%d\n", odd);
    else printf("-1\n");
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--) solve();
}