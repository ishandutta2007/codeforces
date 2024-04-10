#include<stdio.h>
int a,b,i,s,m,n;int main(){scanf("%d",&n);for(i=0;i<n;i++){scanf("%d%d",&a,&b);s-=a,s+=b;if(s>m)m=s;}printf("%d",m);}