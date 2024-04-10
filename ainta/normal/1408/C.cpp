#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[110000], L;
double T1[101000], T2[101000];
void Solve(){
    int i, K, c = 0;
    scanf("%d%d",&n,&L);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    w[n+1]=L;
    T1[0]=0.0,T2[n+1]=0.0;
    for(i=1;i<=n+1;i++){
        T1[i]=T1[i-1] + (double)(w[i]-w[i-1])/i;
    }
    for(i=n;i>=0;i--){
        T2[i]=T2[i+1] + (double)(w[i+1]-w[i])/(n-i+1);
    }
    double b=0.0, e = min(T1[n+1],T2[0]), mid;
    for(int T=0;T<100;T++){
        mid = (b+e)*0.5;
        double rem=mid, s1 = 0.0, s2 = 0.0;
        for(i=1;i<=n+1;i++){
            int d = (w[i]-w[i-1]);
            double t =  min((double)d/i, rem);
            s1 += t*i;
            rem-=t;
        }
        rem = mid;
        for(i=n;i>=0;i--){
            int d = (w[i+1]-w[i]);
            double t =  min((double)d/(n-i+1), rem);
            s2 += t*(n-i+1);
            rem-=t;
        }
        if(s1+s2>=L){
            e=mid;
        }
        else b=mid;
    }
    printf("%.10f\n",(b+e)*0.5);
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}