#include<stdio.h>
int a,b,n,j,R;
int main(){
scanf("%d%d%d",&a,&b,&n);
R=a%b;R*=10;
for(j=0;j<10;j++)if((R+j)%b==0)break;
printf("%d",j>9?-1:a*10+j);
if(j<=9)for(j=0;j<n-1;j++)printf("0");
}