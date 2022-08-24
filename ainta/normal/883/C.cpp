#include<cstdio>
#include<algorithm>
using namespace std;
int A, T, t0, a1, t1, p1, a2, t2, p2;
long long Res = 9e18;
int main(){
    scanf("%d%d%d%d%d%d%d%d%d",&A,&T,&t0,&a1,&t1,&p1,&a2,&t2,&p2);
    int i;
    long long nd = 1ll*t0*A-T;
    for(i=0;;i++){
        if(a1*i >= A){
            if(1ll*t1*A<=T) Res = min(Res, 1ll*p1*i);
            break;
        }
        long long a = A-a1*i, t = nd - 1ll*(t0-t1)*(a1*i);
        if(t <= 0){
            Res = min(Res, 1ll*p1*i);
            continue;
        }
        int c = (a+a2-1)/a2;
        if(t1 <= t2){
            if(1ll*t1*(i*a1) + 1ll*t2*(A - i*a1) <= T) Res = min(Res, 1ll*p1*i + 1ll*p2*c);
        }
        else{
            if(1ll*t1*max(A-c*a2,0) + 1ll*t2*min(c*a2,A) <= T) Res = min(Res, 1ll*p1*i + 1ll*p2*c);
        }
        if(t2 >= t0)continue;
        long long cc = ((t+t0-t2-1)/(t0-t2) + a2 - 1)/a2;
        if(cc >= c)continue;
        Res = min(Res, 1ll*p1*i + 1ll*p2*cc);
    }

    swap(t1,t2);
    swap(p1,p2);
    swap(a1,a2);
    nd = 1ll*t0*A-T;
    for(i=0;;i++){
        if(a1*i >= A){
            if(1ll*t1*A<=T) Res = min(Res, 1ll*p1*i);
            break;
        }
        long long a = A-a1*i, t = nd - 1ll*(t0-t1)*(a1*i);
        if(t <= 0){
            Res = min(Res, 1ll*p1*i);
            continue;
        }
        int c = (a+a2-1)/a2;
        if(t1 <= t2){
            if(1ll*t1*(i*a1) + 1ll*t2*(A - i*a1) <= T) Res = min(Res, 1ll*p1*i + 1ll*p2*c);
        }
        else{
            if(1ll*t1*max(A-c*a2,0) + 1ll*t2*min(c*a2,A) <= T) Res = min(Res, 1ll*p1*i + 1ll*p2*c);
        }
        if(t2 >= t0)continue;
        long long cc = ((t+t0-t2-1)/(t0-t2) + a2 - 1)/a2;
        if(cc >= c)continue;
        Res = min(Res, 1ll*p1*i + 1ll*p2*cc);
    }
    if(Res > 5e18)printf("-1\n");
    else printf("%lld\n",Res);
}