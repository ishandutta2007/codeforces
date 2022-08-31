#include<stdio.h>
int gcd(int p,int q){if(q==0)return p;return gcd(q,p%q);}
int main(){
int a,b,n,chk=0;
scanf("%d%d%d",&a,&b,&n);
while(n>0){if(chk)n-=gcd(b,n);else n-=gcd(a,n);chk=1-chk;}
if(chk)printf("0\n");
else printf("1\n");
}