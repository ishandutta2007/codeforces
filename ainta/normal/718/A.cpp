#include<stdio.h>
char p[201000];
int n, T;
int main(){
    int i, pv, ck = 0, j;
    scanf("%d%d",&n,&T);
    scanf("%s",p+1);
    for(i=1;i<=n;i++){
        if(p[i]=='.')ck=1;
        if(ck && p[i]>='5' && p[i]<='9'){
            break;
        }
    }
    pv = i;
    if(pv == n+1){
        printf("%s\n",p+1);
        return 0;
    }
    for(i=pv;i>=1;i--){
        if(p[i] == '.'){
                for(j=i-1;j>=1;j--){
                    p[j-1] += (p[j]-'0')/10;
                    p[j] = (p[j]-'0')%10 + '0';
                }
                if(p[0]) p[0] = '1';
                for(j=0;j<i;j++){
                    if(p[j])printf("%c",p[j]);
                }
                printf("\n");
                return 0;
        }
        if(p[i] >= '5' && T){
            T--;
            p[i] = '0';
            if(p[i-1] == '.') p[i-2]++;
            else p[i-1]++;
        }
        else break;
    }
    for(i=pv;i>=1;i--)if(p[i]!='0')break;
    pv=i;
    for(i=1;i<=pv;i++)printf("%c",p[i]);
    printf("\n");
}