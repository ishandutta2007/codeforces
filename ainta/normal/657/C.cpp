#include<stdio.h>
#include<algorithm>
using namespace std;
#define SZ 262144
int n, K, C[5], ord[210000];
long long c5, c1, w[210000], P[5][201000], G[201000], IT[SZ+SZ+1];
long long BIT[210000];
struct A{
    int num;
    long long g;
    bool operator<(const A &p)const{
        return g<p.g;
    }
}PP[210000];
void Ins(long long a){
    P[a%5][C[a%5]] = a;
    C[a%5]++;
}
void Ins1(int a, int b){
    a+=SZ;
    IT[a] += b;
    while(a!=1){
        a>>=1;
        IT[a]=IT[a*2]+IT[a*2+1];
    }
}
void Ins2(int a, long long b){
    while(a<=n){
        BIT[a]+=b;
        a+=(a&-a);
    }
}
int Get(){
    int a = 1, c = K;
    while(a<SZ){
        a*=2;
        if(IT[a] < c){
            c-=IT[a];
            a++;
        }
    }
    return a-SZ;
}
long long Sum(int a){
    long long r = 0;
    while(a){
        r+=BIT[a];
        a=a-(a&-a);
    }
    return r;
}
int main(){
    int i, j, pv, t;
    long long Res = 5e18, SS, x;
    scanf("%d%d%lld%lld",&n,&K,&c5,&c1);
    for(i=1;i<=n;i++){
        scanf("%lld",&w[i]);
        w[i] += 1000000000;
    }
    if(c5>c1*5) c5 = c1*5;
    sort(w+1,w+n+1);
    for(i=1;i<=n;i++){
        Ins(w[i]);
        Ins(w[i]+1);
        Ins(w[i]+2);
        Ins(w[i]+3);
        Ins(w[i]+4);
    }
    for(i=0;i<5;i++){
        for(j=1;j<=n;j++){
            x = (i+5-w[j]%5)%5;
            PP[j].num = j;
            if(w[j]%5 <= i){
                G[j] = x*c1 - w[j]/5*c5;
            }
            else{
                G[j] = x*c1 - (w[j]/5+1)*c5;
            }
            PP[j].g = G[j];
        }
        sort(PP+1,PP+n+1);
        for(j=1;j<=n;j++){
            ord[PP[j].num] = j;
        }
        pv = 1;
        for(j=0;j<C[i];j++){
            x = P[i][j];
            while(pv<=n && w[pv] <= x){
                Ins1(ord[pv],1);
                Ins2(ord[pv], G[pv]);
                pv++;
            }
            if(pv > K){
                t = Get();
                SS = Sum(t);
                Res = min(Res, (x/5)*c5*K + SS);
            }
        }
        while(pv>1){
            pv--;
            Ins1(ord[pv],-1);
            Ins2(ord[pv], -G[pv]);
        }
    }
    printf("%lld\n",Res);
}