#include<cstdio>
char p[1010000];
long long res, Mod = 1000000007, c;
int main(){
    int i;
    scanf("%s",p);
    for(i=0;p[i];i++);
    for(i=i-1;i>=0;i--){
        if(p[i]=='b')c=(c+1)%Mod;
        else{
            res=(res+c)%Mod;
            c=c*2%Mod;
        }
    }
    printf("%lld\n",res);
}