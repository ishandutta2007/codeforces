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

const int N=200005;

bool vis[N];
int deg[N],p[N],n,X;

void solve(){
	n=read(),X=read();
	rep(i,1,n)deg[i]=0;
	rep(i,1,n-1){
		int u=read(),v=read();
		deg[u]++,deg[v]++;
	}
	rep(i,1,n)p[read()]=i;
// 	rep(i,1,n)printf("p[%d]=%d ",i,p[i]);
	int rt=max_element(deg+1,deg+n+1)-deg;
	if(deg[rt]!=n-1||is_sorted(p+1,p+n+1)){
		puts("Alice");
		return;
	}
	int inv=n&1;
	rep(i,1,n)vis[i]=0;
	rep(i,1,n)if(!vis[i]){
		int j=i;while(!vis[j])vis[j]=1,j=p[j];
		inv^=1;
	}

	vector<int> ban;
	rep(i,1,n)if(p[i]!=i)ban.pb(i);
	if(SZ(ban)==2&&(X!=ban[0]&&X!=ban[1])){
		puts("Alice");
		return;
	}

	//   unmarked     token
	bool k1=p[rt]==rt,k2=X==rt;
	if(k1&&k2){ 
		cerr<<"type 1\n";
		if(inv)puts("Alice");
		else puts("Bob");
	}else if(k1){
		cerr<<"type 2\n";
		// assert(0);
		if(inv)puts("Bob");
		else puts("Alice");
	}else if(k2){
		cerr<<"type 3\n";
		puts("Bob");
	}else{
		cerr<<"type 4\n";

		// assert(0);
		if(p[X]==rt)puts("Bob");
		else if(inv)puts("Bob");
		else puts("Alice");
	}
}

int main(){
	int T=read();
	while(T--)solve();
	return 0;
}