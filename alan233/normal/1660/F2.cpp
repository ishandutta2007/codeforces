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

const int N=400005;

char a[N];int n;

struct Fen{
    int c[N];
    void init(int n){
        memset(c,0,4*(n+1));
    }
    void ins(int x,int dlt){
        while(x<=2*n+1)c[x]+=dlt,x+=x&-x;
    }
    int qry(int x){
        int ret=0;
        while(x)ret+=c[x],x^=x&-x;
        return ret;
    }
}tr[3];

void solve(){
    scanf("%d%s",&n,a+1);
    rep(i,0,2)tr[i].init(2*n+1);
    int pre=0;ll ans=0;
    rep(i,0,n){
        if(i)pre+=(a[i]=='+'?-1:1);
        int type=(pre%3+3)%3;
        ans+=tr[type].qry(pre+n+1);
        tr[type].ins(pre+n+1,1);
    }
    print(ans,'\n');
}
int main(){
    int T=read();
    while(T--)solve();
    return 0;
}