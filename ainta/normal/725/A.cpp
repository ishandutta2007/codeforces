#include<stdio.h>
int n, cnt;
char p[201000];
int main(){
    int i;
    scanf("%d",&n);
    scanf("%s",p);
    for(i=0;i<n;i++){
        if(p[i]=='>')break;
        cnt++;
    }
    for(i=n-1;i>=0;i--){
        if(p[i]=='<')break;
        cnt++;
    }
    printf("%d\n",cnt);
}