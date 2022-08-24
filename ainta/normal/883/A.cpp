#include<cstdio>
#include<algorithm>
using namespace std;
int n, m;
long long A, d, w[101000], T, R;
void Do(long long x, int &p1, int &p2){
    while(p2<=m && w[p2] <= x+d)p2++;
    p1 = min((x+d)/A + 1, 0ll + n + 1);
}
int main(){
    int i;
    scanf("%d%d%lld%lld",&n,&m,&A,&d);
    for(i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    T = d/A + 1;
    int p1 = 1, p2 = 1;
    while(p1 <= n || p2 <= m){
        long long x1 = 1ll*p1*A, x2 = w[p2];
        if((p2 == m+1) || (p1!=n+1 && x1 < x2)){
            if(p2 == m+1)x2 = 1ll*n*A;
            long long cc = (x2-x1-1)/A;
            long long x = x1;
            if(cc > 100 && T < 100){
                R += cc / T + 1;
                x = x1 + (cc/T)*T*A;
            }
            else R++;
            Do(x, p1, p2);
        }
        else{
            R++;
            Do(x2, p1, p2);
        }
    }
    printf("%lld\n",R);
}