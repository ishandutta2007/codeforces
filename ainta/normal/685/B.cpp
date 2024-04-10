#include<stdio.h>
#include<algorithm>
#include<vector>
#define SZ 524288
using namespace std;
vector<int>E[301000];
int IT[SZ+SZ+2], n, Q, C[301000], Num[301000], cnt, Ed[301000], ReNum[301000];
void DFS(int a){
    Num[a] = ++cnt;
    ReNum[cnt] = a;
    C[a]=1;
    for(int i=0;i<E[a].size();i++){
        DFS(E[a][i]);
        C[a]+=C[E[a][i]];
    }
    Ed[a] = cnt;
}
void Ins(int a, int b){
    a+=SZ;
    IT[a]=b;
    while(a!=1){
        a>>=1;
        IT[a]=max(IT[a*2],IT[a*2+1]);
    }
}
int Do(int a, int c){
    a+=SZ;
    int r = 0;
    while(1){
        r = max(r, IT[a]);
        if(r*2>c)break;
        a = (a-1)>>1;
    }
    while(a<SZ){
        a=a*2+1;
        if(IT[a]*2 <= c) a--;
    }
    return a-SZ;
}
int main(){
    int i, a;
    scanf("%d%d",&n,&Q);
    for(i=2;i<=n;i++){
        scanf("%d",&a);
        E[a].push_back(i);
    }
    DFS(1);
    for(i=1;i<=n;i++){
        Ins(Num[i],C[i]);
    }
    while(Q--){
        scanf("%d",&a);
        printf("%d\n",ReNum[Do(Ed[a],C[a])]);
    }
}