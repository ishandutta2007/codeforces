#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
long long bef, dif;
int Query(long long x){
    dif = abs(x-bef);
    printf("? %lld\n",x);
    fflush(stdout);
    int ck;
    scanf("%d",&ck);
    bef=x;
    return ck;
}
void Answer(long long a){
    printf("= %lld\n",a);
    fflush(stdout);
}
void Solve(){
    long long n;
    scanf("%lld",&n);
    if(n<=10){
        long long res;
        for(int i=0;;i++){
            int ck;
            if(i%2==0)ck = Query(i/2+1);
            if(i%2==1)ck = Query(n-i/2);
            if(i && !ck){
                res = dif+1;
                break;
            }
            if(i==n-1){
                res=1;break;
            }
        }
        Answer(res);
        return;
    }
    long long K = n-1;
    int i, m=0;
    for(i=0;;i++){
        long long t = (1ll<<(i+2))-1;
        if(t > K)break;
    }
    m = i-1;
    vector<long long>V;
    V.push_back((1ll<<m));
    K-=(1ll<<m);
    for(i=m;i>=0;i--){
        V.push_back((1ll<<i));
        K-=(1ll<<i);
    }
    long long b=1,e;
    for(i=0;i<V.size();i+=2)b+=V[i];
    int last = 0;
    long long ans = n, U = 0;
    Query(b);
    e = b+K;
    last = Query(e);
    if(last){
        last = Query((b+e+1)/2);
        e = (b+e+1)/2;
        long long bb = 1, ee = K, mid;
        if(last)ee=dif;
        else bb=dif+1;
        int ck=0;
        while(bb<ee){
            mid = (bb+ee)/2;
            if(!ck){
                b=e-mid;
                last = Query(b);
            }
            else{
                e=b+mid;
                last = Query(e);
            }
            if(last) ee = mid;
            else bb = mid + 1;
            ck = !ck;
        }
        Answer(bb);
        return;
    }
    int chk=0;
    for(i=0;;i++){
        long long tp;
        if(!chk){
            if(i==V.size())break;
            tp = V[i];
        }
        else{
            U/=2;
            if(!U)break;
            tp=U;
        }
        if(i%2==1){
            e+=tp * (1-last*2);
            last = Query(e);
        }
        else{
            b-=tp * (1-last*2);
            last = Query(b);
        }
        if(last){
            ans = dif;
            U=tp;
            chk=1;
        }
    }
    Answer(ans);
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}