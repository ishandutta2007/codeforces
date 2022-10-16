// Author: wlzhouzhuan
#pragma GCC optimize(2,3,"Ofast")
#pragma GCC target("avx","avx2")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) (int(x.size()))
#define pii pair<int,int>
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<class T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<class T>void print(T x,char let){print(x),putchar(let);}
template<class T1,class T2>void ckmin(T1&x,T2 y){if(x>y)x=y;}
template<class T1,class T2>void ckmax(T1&x,T2 y){if(x<y)x=y;}

const int N=50005;

struct Line{
    int l,r;
    friend bool operator < (const Line&x,const Line&y){
        return x.r!=y.r?x.r<y.r:x.l<y.l;
    }
}XZ[N];
int len;

ll a[N],n,x;
int stk[N],top;

void solve(){
    n=read();len=0;
    rep(i,1,n)a[i]=read();
    x=read();
    rep(i,1,n)a[i]=a[i]-x+a[i-1];
    top=0;
//    rep(i,0,n){
//        printf("a[%d]=%lld\n",i,a[i]);
//    }
    rep(i,0,n){
        int l=0,r=top;
        while(l<r){
            int mid=l+r+1>>1;
            if(a[stk[mid]]>a[i])l=mid;
            else r=mid-1;
        }
//        printf("When i=%d,stk=",i);rep(i,1,top)printf("%d ",stk[i]);puts("");
        if(l){
            XZ[++len]={stk[l]+1,i};
//            printf("When i=%d,XZ=(%d,%d)\n",i,stk[l]+1,i);
        }
        if(i){
            while(top&&a[stk[top]]<=a[i-1])top--;
            stk[++top]=i-1;
        }
    }
    sort(XZ+1,XZ+len+1);
    int las=-1,need=0;
    rep(i,1,len){
        if(las<XZ[i].l)las=XZ[i].r,need++;
    }
    printf("%d\n",n-need);
} 

int main(){
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}