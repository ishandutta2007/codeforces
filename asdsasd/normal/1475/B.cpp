#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    scanf("%d", &n);
    int x = n / 2020;
    int y = n % 2020;
    if(x >= y) printf("YES\n");
    else printf("NO\n");
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--) solve();
}