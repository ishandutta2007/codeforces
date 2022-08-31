#include<cstdio>
#include<algorithm>
using namespace std;
long long H, C, M;
void Solve(){
    scanf("%lld%lld%lld",&H,&C,&M);
    if(M*2<=C+H){
        puts("2");
        return;
    }
    if(M>=H){
        puts("1");
        return;
    }
    double t = (double)(H-M)/(2*M-H-C);
    int t1 = t;
    int t2 = t+1;
    long long A1 = H*(t1+1) + C*t1 - M*(2*t1+1), B1 = 2*t1+1;
    long long A2 = H*(t2+1) + C*t2 - M*(2*t2+1), B2 = 2*t2+1;
    if(A1<0)A1=-A1;
    if(A2<0)A2=-A2;
    if(A1*B2<=A2*B1)printf("%d\n",t1*2+1);
    else printf("%d\n",t2*2+1);
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}