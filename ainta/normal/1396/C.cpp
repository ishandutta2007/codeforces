#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
typedef pair<int,int> pii;
int n;
long long r1,r2,r3,d, D[1010000][2], w[1010000], res=5e18;
int main(){
    int i;
    scanf("%d%lld%lld%lld%lld",&n,&r1,&r2,&r3,&d);
    for(i=1;i<=n;i++){
        scanf("%lld",&w[i]);
    }
    D[1][0] = r1*w[1]+r3;
    D[1][1] = min(r2, r1*(w[1]+1));
    for(i=2;i<=n;i++){
        long long t1 = r1*w[i]+r3;
        long long t2 = min(r2, r1*(w[i]+1));
        D[i][0]=min(D[i-1][0]+ t1 + d, D[i-1][1]+t1 + d*3+r1);
//        printf("%d: %lld %lld\n",i,D[i-1][0]+ t1 + d, D[i-1][1]+t1+d*3+r1);
        D[i][1]=D[i-1][0]+d+t2;
        D[i][0]=min(D[i][0], D[i-1][1] + d + t2 + d + r1 + d + r1);
        if(i==n){
            res = min(res, D[i-1][1] + d + t1 + d + r1);
        }
//        printf("%lld %lld\n",D[i][0],D[i][1]);
    }
    res=min(res, min(D[n][0], D[n][1]+d*2+r1));
    printf("%lld\n",res);
}