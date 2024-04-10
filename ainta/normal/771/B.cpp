#include<cstdio>
int n, K, w[52], v[52];
char p[22];
int main(){
    int i, j;
    scanf("%d%d",&n,&K);
    for(i=1;i<K;i++)w[i] = i;
    for(i=K;i<=n;i++){
        scanf("%s",p);
        if(p[0]=='Y'){
            for(j=1;j<=K;j++)v[j]=false;
            for(j=i-K+1;j<i;j++)v[w[j]]=true;
            for(j=1;j<=K;j++)if(!v[j])break;
            w[i] = j;
        }
        else w[i] = w[i-K+1];
    }
    for(i=1;i<=n;i++){
        printf("%c%c ",w[i]/26+'A',w[i]%26+'a');
    }
    printf("\n");
}