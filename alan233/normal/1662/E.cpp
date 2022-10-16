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

const int N=1000005;

int n,p[N],pos[N];
ll ans;

struct Fen{
	int c[N];
	void ins(int x,int dlt){while(x<=n)c[x]+=dlt,x+=x&-x;}
	int qry(int x){int ret=0;while(x)ret+=c[x],x^=x&-x;return ret;}
}tr;

void solve(){
	n=read();
	rep(i,1,n)tr.c[i]=0;
	rep(i,1,n)p[i]=read(),pos[p[i]]=i;
	ans=0;
	rep(i,2,n){
		int cnt;
		if(pos[i-1]<pos[i]){
			cnt=tr.qry(pos[i])-tr.qry(pos[i-1]);
		}else{
			cnt=i-2-(tr.qry(pos[i-1])-tr.qry(pos[i]));
		}
		ans+=1ll*cnt*(n-i+1);
		tr.ins(pos[i-1],1);
	}
	print(ans,'\n');
}

int main(){
	int T=read();
	while(T--)solve();
	return 0;
}