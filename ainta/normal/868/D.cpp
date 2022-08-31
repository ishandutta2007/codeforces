#include<cstdio>
#include<algorithm>
using namespace std;
int D[222][65536];
int n, L[222];
char p[222][222], tp[222];
char B[222][20], E[222][20];
void Make(int num, char *q, int L){
    int i;
    for(i=0;i<L&&i<16;i++){
        B[num][i] = q[i];
        E[num][i] = q[L-1-i];
    }
}
int main(){
    int i, j, k, l, a, b;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%s",p[i]);
        for(j=0;p[i][j];j++);
        L[i] = j;
        for(j=1;j<=15;j++){
            for(k=0;k<=L[i]-j;k++){
                int s = 0;
                for(l=k;l<k+j;l++){
                    s=s*2+p[i][l]-'0';
                }
                D[i][(1<<j) + s]=1;
            }
        }
        Make(i,p[i],L[i]);
    }
    int Q;
    scanf("%d",&Q);
    for(i=n+1;i<=n+Q;i++){
        scanf("%d%d",&a,&b);
        for(j=0;j<65536;j++){
            D[i][j] = D[a][j]|D[b][j];
        }
        int cnt = 0;
        for(j=min(16,L[a])-1;j>=0;j--)tp[cnt++] = E[a][j];
        for(j=0;j<L[b] && j<16;j++)tp[cnt++] = B[b][j];
        for(j=1;j<=15;j++){
            for(k=0;k<=cnt-j;k++){
                int s = 0;
                for(l=k;l<k+j;l++){
                    s=s*2+tp[l]-'0';
                }
                D[i][(1<<j)+s] = 1;
            }
        }
        int r = 0;
        for(j=1;j<=15;j++){
            for(k=0;k<(1<<j);k++){
                if(!D[i][(1<<j) + k])break;
            }
            if(k==(1<<j))r = j;
        }
        printf("%d\n",r);
        cnt = 0;
        for(j=0;j<L[a];j++)tp[cnt++] = p[a][j];
        for(j=0;j<L[b];j++)tp[cnt++] = p[b][j];
        if(cnt < 60){
            for(j=0;j<cnt;j++)p[i][j] = tp[j];
            L[i] = cnt;
        }
        else{
            L[i] = 0;
            for(j=0;j<=20;j++)p[i][L[i]++] = tp[j];
            for(j=cnt-20;j<cnt;j++)p[i][L[i]++] = tp[j];
        }
        Make(i, p[i], L[i]);
    }
}