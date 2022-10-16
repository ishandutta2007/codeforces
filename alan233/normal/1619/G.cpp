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

const int N=200005;
const int inf=2e9;

struct node{
    int x,y,id,timer;
}a[N];
int f[N],jb[N];
int n,k;

int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void merge(int x,int y){
    f[find(x)]=find(y);
}

//bool tag=0;
//int casee=0;
void solve(){
    n=read(),k=read();
    rep(i,1,n){
        a[i].x=read(),a[i].y=read(),a[i].id=i;
        a[i].timer=read();
    }    
//    if(++casee==300){
//        printf("%d %d\n",n,k);
//        rep(i,1,n)printf("%d %d %d\n",a[i].x,a[i].y,a[i].timer);
//        exit(0);
//    }
    sort(a+1,a+n+1,[&](node x,node y){
        return x.x!=y.x?x.x<y.x:x.y<y.y;
    });
//    printf("!!!\n");
//    rep(i,1,n){
//        printf("%d %d\n",a[i].x,a[i].y);
//    }
    iota(f+1,f+n+1,1);
    rep(i,2,n){
        if(a[i].x==a[i-1].x&&a[i].y-a[i-1].y<=k)merge(a[i].id,a[i-1].id);
    }
    sort(a+1,a+n+1,[&](node x,node y){
        return x.y!=y.y?x.y<y.y:x.x<y.x;
    });
//    printf("!!!\n");
//    rep(i,1,n){
//        printf("%d %d\n",a[i].x,a[i].y);
//    }
    rep(i,2,n){
        if(a[i].y==a[i-1].y&&a[i].x-a[i-1].x<=k)merge(a[i].id,a[i-1].id);
    }
    fill(jb+1,jb+n+1,inf);
    rep(i,1,n){
        ckmin(jb[find(a[i].id)],a[i].timer);
    }
    vector<int>ret;
    rep(i,1,n)if(find(i)==i)ret.pb(jb[i]);
    sort(ret.begin(),ret.end());
//    printf(">> debug\n");
//    for(auto it:ret)printf("%d ",it);puts("");
    int ans=-1;
    ret.pop_back();
    ans=0;
    while(SZ(ret)&&ret.back()>ans){
        ans++;
        ret.pop_back();
    }
    printf("%d\n",ans);
}

int main(){
    int T=read();
//    if(T>300)tag=1;
    while(T--)solve();
    return 0;
}