#pragma GCC optimize(2,3,"Ofast")
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) (int(x.size()))
//#define int long long
inline int read(){
    int x=0;char ch=getchar();
    int f=0;
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<typename T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<typename T>void print(T x,char let){
    print(x),putchar(let);
}
template<typename T1,typename T2>void ckmin(T1&x,T2 y){
    if(x>y)x=y;
}
template<typename T1,typename T2>void ckmax(T1&x,T2 y){
    if(x<y)x=y;
}

const int N=100005;

struct node{int x,y,c,id;}a[N],b[N],c[N];
int n;

int p[5],rk[5],aa;

/*
| |
*/
inline bool check1(int lim){
    if(aa){
        sort(b+1,b+n+1,[&](node x,node y){
            if(x.x!=y.x)return x.x<y.x;
            else return rk[x.c]<rk[y.c];
        });
        aa=0;
    }
    int now=1,cnt=0,las=-2e9;
    rep(i,1,n){
        if(now<=3&&b[i].x!=las&&b[i].c==p[now]){
            ++cnt;
            if(cnt==lim)las=b[i].x,now++,cnt=0;
        }
    }
    if(now==4)return 1;
    return 0;
}
inline void rot(){
    for(int i=1;i<=n;i++){
        int tx=b[i].x,ty=b[i].y;
        b[i].x=ty;
        b[i].y=-tx;
    }
}
/*
 
 | | 

*/
bool vis[N];
inline bool check2(int lim){
    if(aa){
        sort(b+1,b+n+1,[&](node x,node y){
            if(x.y!=y.y)return x.y>y.y;
            else return rk[x.c]<rk[y.c];
        });
        rep(i,1,n)c[i]=b[i];
        sort(c+1,c+n+1,[&](node x,node y){
            if(x.x!=y.x)return x.x<y.x;
            else return rk[x.c]<rk[y.c];
        });
        aa=0;
    }
    rep(i,1,n)vis[i]=0;
    int pos=0,cnt=0,lass;
    rep(i,1,n){
        vis[b[i].id]=1;
        if(b[i].c==p[1]){
            ++cnt;
            if(cnt==lim){
                lass=b[i].y;
                pos=i+1;
                break;
            }
        }
    }
    int now=2,las=-2e9;cnt=0;
    rep(i,1,n){
        if(now<=3&&!vis[c[i].id]&&c[i].y!=lass&&c[i].x!=las&&c[i].c==p[now]){
            ++cnt;
            if(cnt==lim){
                las=c[i].x;
                now++;
                cnt=0;
            }
        } 
    }
    if(now==4)return 1;
    return 0;
}
inline bool check(int lim){
    for(int i=1;i<=n;i++)b[i]=a[i];
    if(check1(lim))return 1;
    rot();
    if(check1(lim))return 1;
    for(int i=1;i<=n;i++)b[i]=a[i];
    if(check2(lim))return 1;
    rot();
    if(check2(lim))return 1;
    rot();
    if(check2(lim))return 1;
    rot();
    if(check2(lim))return 1;
    return 0;
}

int gao1(){
    aa=1;
    int l=0,r=n/3;
    while(l<r){
        int mid=l+r+1>>1;
        if(check1(mid))l=mid;
        else r=mid-1;
    }    
    return l;
}
int gao2(){
    aa=1;
    int l=0,r=n/3;
    while(l<r){
        int mid=l+r+1>>1;
        if(check2(mid))l=mid;
        else r=mid-1;
    }    
    return l;
}

int main(){
    n=read();
    rep(i,1,n)a[i].x=read(),a[i].y=read(),a[i].c=read(),a[i].id=i;
    int ans=0;
    iota(p+1,p+4,1);
    do{
        rep(i,1,3)rk[p[i]]=i;
        
        rep(i,1,n)b[i]=a[i];
        ckmax(ans,gao1());
        rot();
        ckmax(ans,gao1());
        
        rep(i,1,n)b[i]=a[i];
        ckmax(ans,gao2());
        rot();
        ckmax(ans,gao2());
        rot();
        ckmax(ans,gao2());
        rot();
        ckmax(ans,gao2());
        
    }while(next_permutation(p+1,p+4));
    printf("%d\n",3*ans);
    return 0;
}