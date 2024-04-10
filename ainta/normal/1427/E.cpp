#include<cstdio>
#include<algorithm>
#include<vector>
#define pll pair<long long, long long>
using namespace std;
long long gcd(long long a, long long b){
    return b?gcd(b,a%b):a;
}
struct point{
    int ck;
    long long a, b;
};
vector<point>R;
void Make(long long a, long long b){
    int i;
    for(i=0;(1ll<<i)<b;i++){
        R.push_back({1,a<<i,a<<i});
    }
    long long bef = 0;
    for(i=0;i<60;i++){
        if((b>>i)&1){
            if(bef==0){
                bef = (a<<i);
            }
            else{
                R.push_back({1,bef,a<<i});
                //printf("%lld + %lld\n",bef,(a<<i));
                bef+=(a<<i);
            }
        }
    }
}
pll Get(long long a, long long b){
    if(a==0)return {0,1};
    if(b==0)return {1,0};
    long long q = a/b, r = a%b;
    pll tp = Get(b,a%b);
    return {tp.second, tp.first - q*tp.second};
}
void Do(long long a, long long b){
    if(a>b)swap(a,b);
    pll t = Get(a,b);
    long long X = t.first, Y = t.second;
    X=abs(X),Y=abs(Y);
    Make(a, X);
    Make(b, Y);
    long long ta = a*X, tb = b*Y;
    int i;
    for(i=0;;i++){
        if( (((a*i)+ta) ^ ((a*i)+tb)) == abs(ta-tb)){
            if(i){
                Make(a,i);
 
                R.push_back({1,ta,a*i});
                R.push_back({1,tb,a*i});
                //printf("%lld + %lld\n",ta,a*i);
                //printf("%lld + %lld\n",tb,a*i);
            }
            R.push_back({2,ta+a*i,tb+a*i});
            //printf("%lld ^ %lld\n",ta+a*i, tb+a*i);
            return;
        }
    }
}
void Go(long long Z){
    if(Z==1)return;
    for(int i=2;;i++){
        long long t = Z^(i*Z);
        if(gcd(t,Z)!=Z){
            Make(Z,i);
            R.push_back({2,i*Z,Z});
            //printf("%lld ^ %lld\n",i*Z,Z);
            Do(t,Z);
            Go(gcd(t,Z));
            return;
        }
    }
}
void Solve(){
    int n;
    scanf("%d",&n);
    Go(n);
    printf("%d\n",R.size());
    for(auto &t: R){
        if(t.ck==1){
            printf("%lld + %lld\n",t.a,t.b);
        }
        else{
            printf("%lld ^ %lld\n",t.a,t.b);
 
        }
    }
}
int main(){
    int TC = 1;
    while(TC--){
        Solve();
    }
}