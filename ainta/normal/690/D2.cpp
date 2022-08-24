#include<stdio.h>
#include<algorithm>
using namespace std;
int Mod = 1000003;
long long Inv(long long a){
    long long r = 1;
    int b = Mod - 2;
    while(b){
        if(b&1)r=r*a%Mod;
        a=a*a%Mod;
        b>>=1;
    }
    return r;
}
long long Fact(int n){
    long long r = 1;
    for(int i=1;i<=n;i++)r=r*i%Mod;
    return r;
}
int main(){
    int n, C, i;
    scanf("%d%d",&n,&C);
    printf("%d\n",(Fact(n+C) * Inv(Fact(n)) % Mod * Inv(Fact(C)) % Mod + Mod - 1)%Mod);
}