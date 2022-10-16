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

const int N=100005;

int n,K;
int a[N],b[N];

void solve(){
    n=read(),K=read();
    if(n==4&&K==3)return puts("-1"),void();
    rep(i,0,n/2-1)a[i]=i,b[i]=(n-1)^i;
    if(K<n-1){
        if(K>0){
            rep(i,0,n/2-1){
                if(a[i]==K){
                    swap(a[i],a[0]);
                    break;
                }
                if(b[i]==K){
                    swap(b[i],a[0]);
                    break;
                }
            }
        }
    }else{
        swap(a[0],b[1]);
        swap(a[2],a[1]);
    }
    rep(i,0,n/2-1)print(a[i],' '),print(b[i],'\n');
}
int main(){
    int T=read();
    while(T--)solve();
    return 0;
}