#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back

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

char a[N];
int p[N],q[N],n;

void solve(){
    n=read();
    vector<int>zero,one;
    rep(i,1,n)p[i]=read();
    scanf("%s",a+1);
    rep(i,1,n){
        if(a[i]=='0'){
            zero.pb(i);
        }else{
            one.pb(i);
        }
    }
    sort(zero.begin(),zero.end(),[&](int x,int y){
        return p[x]<p[y];
    });
    sort(one.begin(),one.end(),[&](int x,int y){
        return p[x]<p[y];
    });
    int cur=1;
    for(auto v:zero)q[v]=cur++;
    for(auto v:one)q[v]=cur++;
    rep(i,1,n)printf("%d ",q[i]);puts("");
}
int main(){
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}