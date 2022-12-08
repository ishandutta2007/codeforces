#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const double eps=1e-12;
const int maxn=100001;
int n,k;
double a[maxn],x,y;
inline double dis(double a,double b,double c,double d)
{
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
inline void work1()
{
    printf("%.10lf\n",min(dis(a[1],0,x,y),dis(a[n],0,x,y))+a[n]-a[1]);
}
inline int dcmp(double a,double b)
{
    if(fabs(a-b)<eps)return 1;
    return 0;
}
inline void work2()
{
    double tmp=min(a[n]-a[k],a[k]-a[1])+a[n]-a[1],ans;
    ans=a[k]-a[1]+a[n]-a[1]+dis(a[n],0,x,y);
    ans=min(ans,a[n]-a[k]+a[n]-a[1]+dis(a[1],0,x,y));
    if(k>1)ans=min(ans,a[n]-a[k]+dis(a[n],0,x,y)+dis(a[k-1],0,x,y)+a[k-1]-a[1]);
    if(k<n)ans=min(ans,a[k]-a[1]+dis(a[1],0,x,y)+dis(a[k+1],0,x,y)+a[n]-a[k+1]);
    int j=0,K=0;
    double ans1=1e18,ans2=1e18,ans3=1e18,ans4=1e18;
    for(int i=1;i<=n;i++)if(a[i]<=x)j=i;
    for(int i=n;i>=1;i--)if(a[i]>x)K=i;
    if(j&&K)ans=min(ans,tmp-(a[K]-a[j])+dis(x,y,a[j],0)+dis(x,y,a[K],0));
    j=0,K=0;
    for(int i=1;i<=n;i++)if(a[i]<x)j=i;
    for(int i=n;i>=1;i--)if(a[i]>=x)K=i;
    if(j&&K)ans=min(ans,tmp-(a[K]-a[j])+dis(x,y,a[j],0)+dis(x,y,a[K],0));
    for(int i=k;i<n;i++)ans=min(ans,min(a[i]-a[k]+a[i]-a[1]+dis(a[1],0,x,y)+dis(x,y,a[i+1],0)+a[n]-a[i+1],a[k]-a[1]+a[i]-a[1]+dis(a[i],0,x,y)+dis(x,y,a[i+1],0)+a[n]-a[i+1]));
    for(int i=2;i<=k;i++)ans=min(ans,min(a[k]-a[i]+a[n]-a[i]+dis(a[n],0,x,y)+dis(x,y,a[i-1],0)+a[i-1]-a[1],a[n]-a[k]+a[n]-a[i]+dis(a[i],0,x,y)+dis(x,y,a[i-1],0)+a[i-1]-a[1]));
    printf("%.10lf\n",ans);
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lf",&a[i]);
    double t=a[k];
    scanf("%lf%lf",&x,&y);
    sort(a+1,a+n+1);
    if(k==n+1)work1();
    else
    {
        for(int i=1;i<=n;i++)if(dcmp(a[i],t))k=i;
        work2();
    }
    return 0;
}