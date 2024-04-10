#include <bits/stdc++.h>
using namespace std;

void solve(){
    int xa, ya, xb, yb, xf, yf;
    scanf("%d %d %d %d %d %d", &xa, &ya, &xb, &yb, &xf, &yf);
    int ans = abs(xa - xb) + abs(ya - yb);
    if (xa == xb && xa == xf){
        if((ya < yf && yf < yb) || (ya > yf && yf > yb)) ans += 2;
    }
    if (ya == yb && ya == yf){
        if((xa < xf && xf < xb) || (xa > xf && xf > xb)) ans += 2;
    }
    printf("%d\n", ans);
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    
}