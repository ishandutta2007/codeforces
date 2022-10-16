// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) ((int)x.size())
#define pii pair<int,int>
template<class T1,class T2>void ckmin(T1&x,T2 y){if(x>y)x=y;}
template<class T1,class T2>void ckmax(T1&x,T2 y){if(x<y)x=y;}
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

const int N=200005;

int a[N],n;
int vis[N];

void solve(){
    n=read();
    memset(vis,0,4*(n+1));
    set<int>s;
    rep(i,0,n+1)s.insert(i);
    rep(i,1,n){
        a[i]=read();
        if(!vis[a[i]])s.erase(a[i]);
        vis[a[i]]++;
    }
    vector<int>zz;
    int p=1;
    while(SZ(s)){
        if(p>n)break;
        auto it=s.begin();
        if(*it==0){
            rep(i,1,n-p+1)zz.pb(0);
            break;
        }
        set<int>tem;
        tem.clear();
        rep(i,0,*it-1)tem.insert(i);
        while(SZ(tem)){
            tem.erase(a[p]);
            vis[a[p]]--;
            if(!vis[a[p]])s.insert(a[p]);
            p++; 
        }
        zz.pb(*it);
    }
    print(SZ(zz),'\n');
    for(auto it:zz)print(it,' ');
    putchar('\n');
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}