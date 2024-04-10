#include<stdio.h>
#include<algorithm>
#include<vector>
#define SZ 262144
#define pii pair<int,int>
using namespace std;
int n, m, phi[1010000], w[201000];
long long IT[SZ+SZ+1], Mod = 1000000007;
bool prime[1010000], v[1010000];
vector<int>E[1001000];
vector<pii>F[201000];
vector<pii>Q[201000];
int Prev[1010000], pv[201000];
long long Res[201000];
void Ins(int a, long long t){
    a+=SZ;
    IT[a] = t;
    while(a!=1){
        a>>=1;
        IT[a]=IT[a*2]*IT[a*2+1]%Mod;
    }
}
long long Gap(int b, int e){
    b+=SZ,e+=SZ;
    long long r = 1;
    while(b<=e){
        if(b&1)r=r*IT[b]%Mod;
        if(!(e&1))r=r*IT[e]%Mod;
        b=(b+1)>>1;
        e=(e-1)>>1;
    }
    return r;
}
int main(){
    int i, j, a, b, x;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        v[w[i]]=true;
    }
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        Q[b].push_back(pii(a,i));
    }
    for(i=1;i<=1000000;i++)phi[i] = i;
    for(i=2;i<=1000000;i++){
        if(prime[i])continue;
        for(j=i;j<=1000000;j+=i){
            prime[j]=true;
            if(v[j])E[j].push_back(i);
            phi[j]=phi[j]/i*(i-1);
        }
    }
    for(i=n;i>=1;i--){
        a = w[i];
        for(j=0;j<E[a].size();j++){
            b = E[a][j];
            if(Prev[b]){
                x = Prev[b];
                F[x].push_back(pii(i,b));
            }
            Prev[b] = i;
        }
    }
    for(i=1;i<=n;i++){
        Ins(i, phi[w[i]]);
        for(j=0;j<F[i].size();j++){
            a=F[i][j].first,b=F[i][j].second;
            Ins(a, IT[SZ+a]*b/(b-1));
        }
        for(j=0;j<Q[i].size();j++){
            a=Q[i][j].first,b=Q[i][j].second;
            Res[b] = Gap(a,i);
        }
    }
    for(i=1;i<=m;i++)printf("%lld\n",Res[i]);
}