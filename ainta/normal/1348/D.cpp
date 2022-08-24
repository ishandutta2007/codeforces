#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int TC;
void Go(int d, long long n){
    int i;
    n-=(d+1);
    long long cc=1;
    printf("%d\n",d);
    for(i=0;i<d;i++){
        long long t = min(n/(d-i),cc);
        printf("%lld ",t);
        n-=t*(d-i);
        cc+=t;
    }
    puts("");
}
void Solve(){
    long long n;
    int i, j;
    scanf("%lld",&n);
    for(i=1;;i++){
        long long s=i+1;
        for(j=1;j<=i;j++){
            s+=(i-j+1)*(1ll<<(j-1));
        }
        if(s>=n){
            Go(i,n);
            return;
        }
    }
}
int main(){
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}