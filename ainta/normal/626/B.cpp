#include<stdio.h>
int D[210][210][210], n, c1, c2, c3;
char p[300];
int main(){
    int i,j,k, s;
    D[1][0][0]=1;
    D[0][1][0]=2;
    D[0][0][1]=4;
    for(s=2;s<=200;s++){
        for(j=0;j<=200;j++){
            for(k=0;k<=200;k++){
                if(j+k>s)break;
                i = s-j-k;
                if(i>=2)D[i][j][k] |= D[i-1][j][k];
                if(j>=2)D[i][j][k] |= D[i][j-1][k];
                if(k>=2)D[i][j][k] |= D[i][j][k-1];
                if(i&&j)D[i][j][k] |= D[i-1][j-1][k+1];
                if(j&&k)D[i][j][k] |= D[i+1][j-1][k-1];
                if(i&&k)D[i][j][k] |= D[i-1][j+1][k-1];
            }
        }
    }
    scanf("%d",&n);
    scanf("%s",p);
    for(i=0;i<n;i++){
        if(p[i]=='R')c1++;
        if(p[i]=='G')c2++;
        if(p[i]=='B')c3++;
    }
    if(D[c1][c2][c3]&4)printf("B");
    if(D[c1][c2][c3]&2)printf("G");
    if(D[c1][c2][c3]&1)printf("R");
}