#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct point{
    int t, p;
    bool operator <(const point &q)const{
        return (long long)t*q.p < (long long)q.t*p;
    }
}w[201000];
int n;
long long be[201000], ed[201000];
double tp;
struct AA{
    int p, num;
    bool operator <(const AA &q)const{
        return p<q.p;
    }
}P[201000];
long long ST, s1, s2;
int main(){
    int i, TT = 70, pv, j, ck;
    double bb=0.0,ee=1.0,mid, MM, tp;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&w[i].p);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i].t);
        ST += w[i].t;
    }
    sort(w+1,w+n+1);
    pv = -1;
    s1 = s2 = 0;
    for(i=1;i<=n;i++){
        if(i==1 || (long long)w[i-1].t*w[i].p < (long long)w[i-1].p*w[i].t){
            if(pv!=-1){
                for(j=pv;j<i;j++){
                    be[j] = s1 + w[j].t;
                    ed[j] = s2;
                }
            }
            pv = i;
            s1 = s2;
        }
        s2 += w[i].t;
    }
    for(j=pv;j<=n;j++){
        be[j] = s1 + w[j].t;
        ed[j] = s2;
    }
    for(i=1;i<=n;i++){
        P[i].p = w[i].p, P[i].num = i;
    }
    sort(P+1,P+n+1);
    while(TT--){
        mid = (bb+ee)*0.5;
        pv = 1;
        MM = -1e5;
        ck = 0;
        for(i=1;i<=n;i++){
            while(pv<=n && P[pv].p < P[i].p){
                tp = P[pv].p*(1.0 - mid * be[P[pv].num] / ST);
                if(MM<tp)MM=tp;
                pv++;
            }
            tp = P[i].p*(1.0 - mid * ed[P[i].num] / ST);
            if(MM > tp + 1e-8){
                ck = 1;
            }
        }
        if(ck)ee = mid;
        else bb = mid;
    }
    printf("%.11lf\n",bb);
}