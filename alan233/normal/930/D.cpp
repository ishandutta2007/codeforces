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

const int N=200005;

struct node{
    int x,y;
}a[N],b[N];
int n;

int poolpmax[N<<1],*pmax=poolpmax+N,poolpmin[N<<1],*pmin=poolpmin+N;
int poolsmax[N<<1],*smax=poolsmax+N,poolsmin[N<<1],*smin=poolsmin+N;

ll sol(int opt){
    sort(a+1,a+n+1,[&](node x,node y){
        return x.x<y.x;
    });
    int j=1;
    pmax[-200001]=-1e9,pmin[-200001]=1e9;
    rep(i,-200000,200000){
        pmax[i]=pmax[i-1],pmin[i]=pmin[i-1];
        if((i%2+2)%2!=opt)continue;
        while(j<=n&&a[j].x<=i){
            if((a[j].x%2+2)%2==opt){
                ++j;
                continue;
            }
            ckmax(pmax[i],a[j].y);
            ckmin(pmin[i],a[j].y);
            ++j;
        }
    }
    smax[200001]=-1e9,smin[200001]=1e9;
    j=n;
    per(i,200000,-200000){
        smax[i]=smax[i+1],smin[i]=smin[i+1];
        while(j>=1&&a[j].x>=i){
            if((a[j].x%2+2)%2==opt){
                --j;
                continue;
            }
            ckmax(smax[i],a[j].y);
            ckmin(smin[i],a[j].y);
            --j;
        }
    }
    ll ans=0;
    rep(i,-200000,200000){
        if((i%2+2)%2!=opt)continue;
        int L=max(pmin[i],smin[i]);
        int R=min(pmax[i],smax[i]);
        while((L%2+2)%2!=opt)L++;
        while((R%2+2)%2!=opt)R--;
        if(L>R)continue;
//        printf("i=%d,L=%d,R=%d\n",i,L,R);
        ans+=(R-L)/2+1;
    }
    return ans;
}

int main(){
    n=read();
    rep(i,1,n){
        int x=read(),y=read();
        a[i].x=x+y;
        a[i].y=x-y;
    }
    print(sol(0)+sol(1),'\n');
    return 0;
}