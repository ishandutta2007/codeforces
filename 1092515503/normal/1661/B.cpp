#include<bits/stdc++.h>
using namespace std;
int T;
void mina(){
    int x;
    scanf("%d",&x);
    int mn=0x3f3f3f3f;
    for(int i=0;i<=16;i++,(++x)%=32768){
        int y=x,j=i;
        while(y)(y<<=1)%=32768,j++;
        mn=min(mn,j);
    }
    printf("%d ",mn);
}
int main(){
    scanf("%d",&T);
    while(T--)mina();puts("");
    return 0;
}