#include<stdio.h>
#include<algorithm>
using namespace std;
char p[1010000], q[1010000];
int n, m, Next[1010000][20], cc[1010000];
void Do(int K, int d){
    int i, j;
    for(i=0;i<d;i++)cc[i]=0;
    for(i=0;i<K;i++)cc[i%d]++;
    for(i=1;i<d;i++)cc[i]+=cc[i-1];
    for(i=K-1;i>=0;i--){
        Next[i+1][0] = --cc[i%d];
    }
    for(i=0;i<19;i++){
        for(j=1;j<=K;j++){
            Next[j][i+1]=Next[Next[j][i]][i];
        }
    }
}
int Get2(int a, int r){
    int i = 0;
    while(r){
        if(r&1)a = Next[a][i];
        i++;r>>=1;
    }
    return a;
}
int Get(int be, int cc){
    int pp = Get2(be,cc);
    if(pp != 0) return cc+pp-be;
    int i, r = 0, x = be;
    for(i=19;i>=0;i--){
        if(Next[x][i]){
            x=Next[x][i];
            r += (1<<i);
        }
    }
    return (r+1-be);
}
int main(){
    int i, K, d, t, tp;
    scanf("%s",p);
    scanf("%d",&m);
    for(i=0;p[i];i++);
    n=i;
    while(m--){
        scanf("%d%d",&K,&d);
        Do(K,d);
        for(i=1;i<=n;i++){
            t = min(n-i+1,n-K+1);
            if(i<=K)tp = Get(i,t);
            else tp = Get(K,t);
            q[i+tp-1] = p[i-1];
        }
        for(i=0;i<n;i++)p[i]=q[i];
        printf("%s\n",p);
    }
}