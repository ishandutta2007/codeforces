// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mset(s,t) memset(s,t,sizeof(s))
#define mcpy(s,t) memcpy(s,t,sizeof(t))
#define SZ(x) ((int)x.size())
#define pb push_back
#define eb emplace_back
#define fir first
#define sec second

template<class T1,class T2>bool ckmax(T1 &a,T2 b){if(a<b)return a=b,1;else return 0;}
template<class T1,class T2>bool ckmin(T1 &a,T2 b){if(a>b)return a=b,1;else return 0;}

inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<typename T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<typename T>void print(T x,char ch){
    print(x),putchar(ch);
}

const int N=2005;
const double eps=1e-9;

double a[N],b[N],c[N];
int n,A,B;

int cnt1,cnt2;double res;
void check(double mid1,double mid2){
    cnt1=cnt2=res=0;
    rep(i,1,n){
        double tmp=0;int flag=0;
        if(a[i]-mid1>tmp+eps)tmp=a[i]-mid1,flag=1;
        if(b[i]-mid2>tmp+eps)tmp=b[i]-mid2,flag=2;
        if(c[i]-mid1-mid2>tmp+eps)tmp=c[i]-mid1-mid2,flag=3;
        if(flag&1)cnt1++;
        if(flag&2)cnt2++;
        res+=tmp;
    }
}

int main(){
    scanf("%d%d%d",&n,&A,&B);
    rep(i,1,n)scanf("%lf",&a[i]);
    rep(i,1,n)scanf("%lf",&b[i]),c[i]=1-(1-a[i])*(1-b[i]);
    double l1=0,r1=1,ans1,ans2;
    while(r1-l1>eps){
        double mid1=(l1+r1)/2;
        double l2=0,r2=1;
        while(r2-l2>eps){
            double mid2=(l2+r2)/2;
            check(mid1,mid2);
            ans2=mid2;
            if(cnt2==B)break;
            if(cnt2>B)l2=mid2;
            else r2=mid2;
        }
        check(mid1,ans2);
        ans1=mid1;
        if(cnt1==A)break;
        if(cnt1>A)l1=mid1;
        else r1=mid1;
    }
    printf("%.10f\n",res+ans1*A+ans2*B);
    return 0;
}