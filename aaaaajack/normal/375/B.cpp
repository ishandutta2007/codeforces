#include<cstdio>
#include<iostream>
#include<string>
#define msize 5010
using namespace std;
int count[msize][msize]={};
char c[msize];
int main(){
    int n,m,i,j,s,k,x,max=0;
    scanf("%d%d",&n,&m);
    getchar();
    for(i=0;i<n;i++){
        gets(c);
        s=0;
        for(j=0;j<m;j++){
            if(c[j]=='0'){
                s=0;
            }
            else{
                count[j][++s]++;
            }
        }
    }
    for(i=0;i<m;i++){
        for(j=m;j>0;j--){
            if(count[i][j]*j>max) max=count[i][j]*j;
            count[i][j-1]+=count[i][j];
        }
    }
    printf("%d\n",max);
    return 0;
}