#include <bits/stdc++.h>
using namespace std;

int main() {
    int dt1,dt2,T2,ini,fim;
    scanf("%*d%d",&dt1);
    scanf("%d%d",&T2,&dt2);
    int x,y;
    scanf("%d:%d",&x,&y);
    ini = 60*x+y;
    fim = ini + dt1;
    int ans = 0;
    for(int L = 5 * 60; L < 24 * 60; L += T2){
        int R = L + dt2;
        if(L < fim && R > ini)
            ans++;
    }
    printf("%d\n",ans);
}