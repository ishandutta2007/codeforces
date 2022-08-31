#include<stdio.h>
#include<algorithm>
using namespace std;
int n, Q, po[10], res;
char p[10];
bool v[1000000];
struct A{
    char p[4],q[3];
}w[50];
void DFS(int a, int cnt){
    if(v[cnt])return;
    v[cnt]=true;
    if(a==n-1){
        res++;
        return;
    }
    int i, tcnt;
    for(i=0;i<Q;i++){
        if(w[i].q[0] != p[a])continue;
        tcnt = cnt;
        cnt += po[a]*(w[i].p[1]-p[a]);
        cnt += po[a+1]*(w[i].p[0]-'a'+1);
        p[a] = w[i].p[1];
        p[a+1] = w[i].p[0];
        DFS(a+1, cnt);
        cnt = tcnt;
        p[a+1]=0;
        p[a] = w[i].q[0];
    }
}
int main(){
    int i;
    scanf("%d%d",&n,&Q);
    for(i=0;i<Q;i++){
        scanf("%s%s",w[i].p,w[i].q);
    }
    p[0]='a';
    po[0]=1;
    for(i=0;i<6;i++)po[i+1]=po[i]*10;
    DFS(0,1);
    printf("%d\n",res);
}