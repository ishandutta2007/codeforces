#include<cstdio>
int x[9],y[9],i,j,t;
main(){
    for(i=1;i<=8;i++)scanf("%d%d",&x[i],&y[i]);
    for(i=1;i<=7;i++)
    for(j=i+1;j<=8;j++)
    if(x[i]>x[j]||(x[i]==x[j]&&y[i]>y[j]))
    t=x[i],x[i]=x[j],x[j]=t,t=y[i],y[i]=y[j],y[j]=t;                
    printf(!(x[1]==x[2]&&x[2]==x[3]) || !(x[4]==x[5]) || !(x[7]==x[6]&&x[7]==x[8]) || !(y[1]==y[4]&&y[4]==y[6]) || !(y[2]==y[7]) || !(y[3]==y[5]&&y[5]==y[8]) || !(x[1]!=x[4]&&x[4]!=x[6]) || !(y[1]!=y[2]&&y[2]!=y[3])?"ugly":"respectable");
}