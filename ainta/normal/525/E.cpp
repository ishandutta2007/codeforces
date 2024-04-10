#include<stdio.h>
#include<algorithm>
#include<unordered_map>
using namespace std;
int n, mid, CC;
unordered_map<long long,long long>Map[26];
long long w[26][2], S, Res;
void DFS1(int a, int c, long long K){
    if(K>S)return;
    if(a==mid+1){
        Map[c][K]++;
        return;
    }
    DFS1(a+1,c,K);
    DFS1(a+1,c,K+w[a][0]);
    if(w[a][1]!=-1)DFS1(a+1,c+1,K+w[a][1]);
}
void DFS2(int a, int c, long long K){
    if(K>S)return;
    if(c>CC)return;
    if(a==n+1){
        int i;
        for(i=0;i<=CC-c;i++)Res += Map[i][S-K];
        return;
    }
    DFS2(a+1,c,K);
    DFS2(a+1,c,K+w[a][0]);
    if(w[a][1]!=-1)DFS2(a+1,c+1,K+w[a][1]);
}
int main(){
    int i, j;
    long long t;
    scanf("%d%d%lld",&n,&CC,&S);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i][0]);
        t=1;
        for(j=1;j<=w[i][0];j++){
            t*=j;
            if(t>S){
                w[i][1]=-1;
                break;
            }
        }
        if(j==w[i][0]+1)w[i][1]=t;
    }
    mid = min(n,13);
    DFS1(1,0,0);
    DFS2(mid+1,0,0);
    printf("%lld\n",Res);
}