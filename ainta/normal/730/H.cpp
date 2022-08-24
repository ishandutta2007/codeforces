#include<stdio.h>
int n, m, L[110], chk[110];
char p[110][110], q[110];
int main(){
    int i, j, a, T;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%s",p[i]);
        for(j=0;p[i][j];j++);
        L[i]=j;
    }
    for(i=0;i<m;i++){
        scanf("%d",&a);
        chk[a]=1;
        if(i==0)T=L[a];
        else{
            if(T!=L[a]){
                printf("No\n");
                return 0;
            }
        }
    }
    for(i=0;i<T;i++){
        char ck = 0;
        for(j=1;j<=n;j++){
            if(!chk[j])continue;
            if(!ck)ck = p[j][i];
            else{
                if(ck!=p[j][i])break;
            }
        }
        if(j==n+1)q[i] = ck;
        else q[i] = '?';
    }
    for(i=1;i<=n;i++){
        if(chk[i]||L[i]!=T)continue;
        for(j=0;j<T;j++){
            if(q[j]!='?' && q[j]!=p[i][j])break;
        }
        if(j==T){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    printf("%s\n",q);
}