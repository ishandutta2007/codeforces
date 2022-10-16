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

const int N=100005;
const int B=350;

/*
p: i->p[i]
q: p[i]->i
*/
int big[N];
int p[N],q[N],n,m;

int jump(int x){
    rep(i,1,B)x=p[x];
    return x;
}

int main(){
    n=read(),m=read();
    rep(i,1,n)p[i]=read(),q[p[i]]=i;
    rep(i,1,n)big[i]=jump(i);
    while(m--){
        int opt=read(),x=read(),y=read();
        if(opt==1){
            swap(q[p[x]],q[p[y]]);
            swap(p[x],p[y]);
            int tox=jump(x),toy=jump(y);
            rep(i,1,B){
                big[x]=tox,big[y]=toy;
                x=q[x],y=q[y];
                tox=q[tox],toy=q[toy];
            }
        }else{
            while(y>=B)x=big[x],y-=B;
            while(y--)x=p[x];
            print(x,'\n'); 
        }
    }
    return 0;
}