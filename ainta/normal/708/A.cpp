#include<stdio.h>
char p[101000];
int main(){
    int i, n, pv = -1;
    scanf("%s",p);
    for(i=0;p[i];i++){
        if(p[i]!='a'&&pv==-1)pv = i;
    }
    n = i;
    if(pv!=-1){
        for(i=pv;p[i]!='a'&&i<n;i++){
            p[i]--;
        }
    }
    else p[n-1]='z';
    printf("%s\n",p);
}