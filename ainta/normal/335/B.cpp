#include<stdio.h>
char p[50010],save[2600];
int n,i,j,c[26],D[2600][2600],Path[2600][2600],x,y,M,C,ck;
int main(){
    scanf("%s",p+1);
    for(i=1;p[i];i++)c[p[i]-'a']++;
    n=i-1;
    for(i=0;i<26;i++){
        if(c[i]>=100){
            for(j=0;j<100;j++)printf("%c",i+'a');
            return 0;
        }
    }
    for(i=n-1;i>=1;i--){
        for(j=1;j<=n-i;j++){
            D[j][j+i]=D[j][j+i+1],Path[j][j+i]=1;
            if(D[j][j+i]<D[j-1][j+i])D[j][j+i]=D[j-1][j+i],Path[j][j+i]=2;
            if(p[j]==p[j+i])D[j][j+i]=D[j-1][j+i+1]+2,Path[j][j+i]=3;
            if(D[j][j+i]==100)x=j,y=j+i;
        }
    }
    if(!x){
        for(i=1;i<n;i++)if(D[i][i+1]>M)M=D[i][i+1],x=i,y=i+1;
        for(i=1;i<n-1;i++)if(D[i][i+2]+1>M)M=D[i][i+2]+1,x=i,y=i+2,ck=i+1;
        if(M==0)ck=1;
    }
    while(x>=1 && y<=n){
        if(Path[x][y]==3)save[++C]=p[x],x--,y++;
        else if(Path[x][y]==2)x--;
        else y++;
    }
    for(i=C;i>=1;i--)printf("%c",save[i]);
    if(ck)printf("%c",p[ck]);
    for(i=1;i<=C;i++)printf("%c",save[i]);
}