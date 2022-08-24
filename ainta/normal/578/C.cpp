#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
int w[201000];
double A[201000], S[201000];
double Gap(double a){
    int i;
    for(i=1;i<=n;i++)A[i]=w[i]-a;
    for(i=1;i<=n;i++)S[i]=S[i-1]+A[i];
    double Mx=0.0,Mn=0.0,Res=0.0;
    for(i=1;i<=n;i++){
        Mx = max(Mx,S[i]);
        Mn = min(Mn,S[i]);
    }
    return Mx-Mn;
}
int main(){
    double be = -10000.0, ed = 10000.0, p1, p2, g1,g2,g3,g4;
    scanf("%d",&n);
    int i, cnt = 0;
    for(i=1;i<=n;i++)scanf("%d",&w[i]);
    while(be<=ed){
        p1 = (be*2.0+ed)/3.0;
        p2 = (be+ed*2.0)/3.0;
        g1 = Gap(be);
        g2 = Gap(ed);
        g3 = Gap(p1);
        g4 = Gap(p2);
        if(max(max(g1,g2),max(g3,g4)) - min(min(g1,g2),min(g3,g4)) < 3e-7)break;
        cnt++;
        if(cnt==100)break;
        if(g3 < g4)ed = p2;
        else be = p1;
    }
    printf("%.11lf\n",min(min(g1,g2),min(g3,g4)));
}