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

char a[10][10005];
int score[10000];
int id[10000],n,m;
int p[10000],ans;
int cont[10000];

void solve(){
    n=read(),m=read();
    rep(i,0,n-1)score[i]=read();
    rep(i,0,n-1){
        scanf("%s",a[i]);
        rep(j,0,m-1)a[i][j]-='0';
    }
    int all=1<<n;
    ans=-1e9;
    rep(st,0,all-1){
        rep(j,0,m-1)cont[j]=0,id[j]=j;
        int qwq=0;
        rep(i,0,n-1){
            if(st>>i&1){// '+'
                qwq-=score[i];
                rep(j,0,m-1)if(a[i][j])cont[j]++;
            }else{
                qwq+=score[i];
                rep(j,0,m-1)if(a[i][j])cont[j]--;
            }
        }
        sort(id,id+m,[&](int x,int y){
            return cont[x]<cont[y];
        });
        rep(i,0,m-1)qwq+=cont[id[i]]*(i+1);
        if(qwq>ans){
            ans=qwq;
            rep(i,0,m-1)p[id[i]]=i;
        }
    }
//    cerr<<"ans="<<ans<<'\n';
    rep(i,0,m-1)printf("%d ",p[i]+1);puts("");
}

int main(){
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}