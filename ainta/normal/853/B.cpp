#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, K;
long long M[101000];
long long B[1010000], E[1010000], S, res = 1e18;
struct point{
    int t, a, b, c;
    bool operator <(const point &p)const{
        return t<p.t;
    }
}w[101000];
int main(){
    int i;
    scanf("%d%d%d",&n,&m,&K);
    for(i=1;i<=m;i++){
        scanf("%d%d%d%d",&w[i].t,&w[i].a,&w[i].b,&w[i].c);
    }
    sort(w+1,w+m+1);
    for(i=1;i<=n;i++)M[i]=1e12;
    B[0] = S = (long long)1e12*n;
    int pv = 1;
    for(i=1;i<=1000000;i++){
        while(w[pv].t <= i && pv <= m){
            if(!w[pv].b){
                if(M[w[pv].a] > w[pv].c){
                    S -= M[w[pv].a] - w[pv].c;
                    M[w[pv].a] = w[pv].c;
                }
            }
            pv++;
        }
        B[i] = S;
    }
    
    for(i=1;i<=n;i++)M[i]=1e12;
    E[1000001] = S = (long long)1e12*n;
    
    pv = m;
    for(i=1000000;i>=1;i--){
        while(w[pv].t >= i && pv >= 1){
            if(!w[pv].a){
                if(M[w[pv].b] > w[pv].c){
                    S -= M[w[pv].b] - w[pv].c;
                    M[w[pv].b] = w[pv].c;
                }
            }
            pv--;
        }
        E[i] = S;
    }
    
    for(i=0;i<=1000000-K;i++){
        res = min(res, B[i]+E[i+K+1]);
    }
    printf("%lld\n",res > 1e12 ? -1 : res);
}