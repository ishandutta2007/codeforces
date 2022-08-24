#include<cstdio>
#include<algorithm>
#define pll pair<long long, long long>
using namespace std;
pll Calc(int L, long long c){
    if(L==0)return {0ll,0ll};
    long long t = c >> (L-2);
    long long M = (1ll<<(L-2))-1;
    pll r = Calc(L-2,c&M);
    if(t==1){
        r.first^=(2ll<<(L-2));
        r.second^=(3ll<<(L-2));
    }
    if(t==2){
        r.first^=(3ll<<(L-2));
        r.second^=(1ll<<(L-2));
    }
    if(t==3){
        r.first^=(1ll<<(L-2));
        r.second^=(2ll<<(L-2));
    }
    return r;
}
void Solve(){
    int i;
    long long K;
    scanf("%lld",&K);
    for(i=1;;i+=2){
        long long b1 = 1ll<<(i-1), e1 = (1ll<<i);
        long long b2 = (1ll<<i);
        long long c = (e1-b1)*3;
        if(K>c){
            K-=c;
            continue;
        }
        if(K%3==1){
            printf("%lld\n",b1 + K/3);
            return;
        }
        long long z = (K-1)/3;
        pll t = Calc(i-1, z);
        t.first += b2;
        t.second += b2+b1;
        if(K%3==2)printf("%lld\n",t.first);
        else printf("%lld\n",t.second);
        return;
    }
}
int main(){
    int TC, i, j, k, cnt=0;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}