#include<stdio.h>
char p[4][4],q[4][4],a[10],b[4];
int c1, c2, i, j;
int main(){
    scanf("%s",p[0]);
    scanf("%s",p[1]);
    scanf("%s",q[0]);
    scanf("%s",q[1]);
    if(p[0][0]!='X')a[c1++] = p[0][0];
    if(p[0][1]!='X')a[c1++] = p[0][1];
    if(p[1][1]!='X')a[c1++] = p[1][1];
    if(p[1][0]!='X')a[c1++] = p[1][0];
    if(q[0][0]!='X')b[c2++] = q[0][0];
    if(q[0][1]!='X')b[c2++] = q[0][1];
    if(q[1][1]!='X')b[c2++] = q[1][1];
    if(q[1][0]!='X')b[c2++] = q[1][0];
    for(i=3;i<6;i++)a[i]=a[i-3];
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)if(b[j]!=a[i+j])break;
        if(j==3)break;
    }
    if(i==3)printf("NO\n");
    else printf("YES\n");
}