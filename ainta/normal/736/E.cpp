#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, SS[3010], s, R[3010];
char p[3010][3010];
struct A{
    int c, num;
    bool operator<(const A &p)const{
        return c>p.c;
    }
}w[3010];
void Make(int a, int b, int c){
    a = w[a].num, b = w[b].num;
    if(c==2)p[a][b] = 'W', p[b][a] = 'L';
    if(c==1)p[a][b] = p[b][a] = 'D';
    if(c==0)p[a][b] = 'L', p[b][a] = 'W';
}
int main(){
    int i, j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        p[i][i]='X';
        SS[i] = SS[i-1] + 2*(n-i);
        w[i].num = i;
    }
    for(i=1;i<=m;i++){
        scanf("%d",&w[i].c);
        s += w[i].c;
        if(s > SS[i]){
            printf("no\n");
            return 0;
        }
    }
    if(SS[n] > s + w[m].c * (n-m)){
        printf("no\n");
        return 0;
    }
    printf("yes\n");
    for(i=m+1;i<=n;i++){
        w[i].c = (SS[n] - s + n-i)/(n-i+1);
        s += w[i].c;
    }
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            if((n-j+1) * 2 == w[i].c){
                w[i].c-=2;
                Make(i,j,2);
                continue;
            }
            int t;
            if((n-j+1) * 2 - 1 == w[i].c){
                t = min(1,w[j].c);
                w[j].c -= t;
                w[i].c -= (2-t);
                Make(i,j, 2-t);
                continue;
            }
            t = min(2,w[j].c);
            w[j].c -= t;
            w[i].c -= (2-t);
            Make(i,j,2-t);
        }
        sort(w+i+1, w+n+1);
    }
    for(i=1;i<=n;i++)printf("%s\n",p[i]+1);
}