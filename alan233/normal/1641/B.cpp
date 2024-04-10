// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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

const int N=100005;

vector<pii> ans1;
vector<int> ans2;
int a[N],b[N],n;

void solve(){
	n=read();
	ans1.clear(),ans2.clear();
	rep(i,1,n)a[i]=read(),b[i]=a[i];
	sort(a+1,a+n+1);
	int cnt=0;
	for(int i=1,j;i<=n;i++){
		j=i;
		while(j<n&&a[i]==a[j+1])++j;
		if((j-i+1)&1){
			puts("-1");
			return;
		}
		i=j;
	}
	for(int i=1,k1=n/2;i<=k1;i++){
		int l=i,r;
		per(j,n,i+1)if(b[i]==b[j])r=j;
		for(int k=0;k<r-l-1;k++)ans1.pb({cnt+k+r,b[k+l+1]});
		reverse(b+l+1,b+r),n--,ans2.pb((r-l)*2);
		rep(j,r,n)b[j]=b[j+1];cnt+=(r-l)*2-1;
	}
	print(SZ(ans1),'\n');
	for(auto [x,y]:ans1)printf("%d %d\n",x,y);
	print(SZ(ans2),'\n');
	for(auto it:ans2)print(it,' ');
	puts("");
}

int main(){
	// freopen("data.in","r",stdin);
	int T=read();
	while(T--)solve();
	return 0;
}