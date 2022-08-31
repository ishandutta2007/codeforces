/*#include<stdio.h>
long long D[51], DP[51];
int Nxt[51];
bool v[51];
void Add(int ed, int a, int b){
    v[b]=true;
    Nxt[a]=b;
    printf("%d ",ed+b);
}
bool Chk(int a, int b){
    if(v[b])return false;
    Nxt[a]=b;
    int t=a,i;
    for(i=1;i<=60;i++){
        t=Nxt[t];
    }
    Nxt[a]=0;
    if(t)return false;
    return true;
}
void Do2(int ed, int n, long long K){
    int i, j;
    for(i=1;i<=n;i++){
        v[i]=false;
        Nxt[i]=0;
    }
    Add(ed, 1,n);
    if(n==1)return;
    for(i=2;i<n;i++){
        for(j=1;j<=n;j++){
            if(!Chk(i,j))continue;
            if(K<=D[n-i+1])break;
            K-=D[n-i+1];
        }
        Add(ed, i, j);
    }
    for(i=1;i<=n;i++)if(!v[i])printf("%d ",ed+i);
}
void Do(int ed, int n, long long K){
    if(!n)return;
    int i;
    long long S = 0, t;
    for(i=1;i<=n;i++){
        if((K-S)/D[i] <DP[n-i])break;
        if(S+D[i]*DP[n-i]>=K)break;
        S+=D[i]*DP[n-i];
    }
    K-=S;
    t = (K-1)/DP[n-i];
    Do2(ed, i, t+1);
    Do(ed+i, n-i, K-t*DP[n-i]);
}
int main(){
    int i, j, n;
    long long K;
    scanf("%d%lld",&n,&K);
    D[1]=D[2]=1;
    DP[0]=1;
    for(i=3;i<=n;i++){
        if(K/D[i-1] < (i-2))D[i]=K+1;
        else D[i]=D[i-1]*(i-2);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            if(DP[i]>K)break;
            if((K-DP[i])/D[j] < DP[i-j])DP[i]=K+1;
            else DP[i]+=DP[i-j]*D[j];
        }
    }
    Do(0, n,K);
}
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, Mod = 1000000007, Res;
int ck[101000];
bool v[101000];
vector<int>E[101000], L[101000];
void DFS(int a, int x){
    ck[a]=x;
    v[a]=true;
    int i;
    for(i=0;i<E[a].size();i++){
        if(!v[E[a][i]]){
            DFS(E[a][i],x^L[a][i]);
        }
    }
}
int main(){
    int i, a, b, c, j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d%d%d",&a,&b,&c);
        c=!c;
        E[a].push_back(b);L[a].push_back(c);
        E[b].push_back(a);L[b].push_back(c);
    }
    c=0;
    for(i=1;i<=n;i++){
        if(!v[i]){
            DFS(i,0);
            c++;
        }
    }
    b=0;
    for(i=1;i<=n;i++){
        for(j=0;j<E[i].size();j++){
            a=E[i][j];
            if((ck[i]^ck[a]) != L[i][j]){
                b=1;
            }
        }
    }
    if(b){
        printf("0\n");
    }
    else{
        Res=1;
        for(i=1;i<c;i++)Res=Res*2%Mod;
        printf("%d\n",Res);
    }
}