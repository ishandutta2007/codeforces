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

int x,d;

bool check(int x){
    if(x<2)return 0;
    for(int i=2;i*i<=x;i++)if(x%i==0)return 0;
    return 1;
}

void solve(){
    x=read(),d=read();
    int s=0;
    while(x%d==0)x/=d,s++;
    if(s==1){
        puts("NO");
        return;
    }
    if(x>1&&!check(x))puts("YES");
    else{
        if(s>=(3+(d==1ll*x*x))&&(d>1&&!check(d)))puts("YES");
        else puts("NO");
    }
}

int main(){
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}