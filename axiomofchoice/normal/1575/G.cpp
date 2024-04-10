#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
	x=0;char o,f=1;
	while(o=getchar(),o<48)if(o==45)f=-f;
	do x=(x<<3)+(x<<1)+(o^48);
	while(o=getchar(),o>47);
	x*=f;
}
template<class T>inline void print(T x,int op=1){
	static int top,stk[105];
	if(x<0)x=-x,putchar('-');
	if(x==0)putchar('0');
	while(x)stk[++top]=x%10,x/=10;
	while(top)putchar(stk[top--]+'0');
	if(~op)putchar(" \n"[op]);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int M=1e5+5;
const int P=1e9+7;
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int n,A[M],tmp[M],cnt[M];
vector<int>fac[M];
vector<int>Q[M];
vector<int>vi,all;

inline void add(int &x,int y){
	x+=y;
	if(x>=P)x-=P;
}
void solve1(int i){
	for(int j=i;j<=n;j+=i)cnt[A[j]]++;
	for(int j=1;j<=1e5;j++)for(int k=j+j;k<=1e5;k+=j)cnt[j]+=cnt[k];
	for(int j=1e5;j>=1;j--)if(cnt[j]){
		cnt[j]=1ll*cnt[j]*cnt[j]%P;
		for(int k=j+j;k<=1e5;k+=j)add(cnt[j],P-cnt[k]);
		tmp[i]=(tmp[i]+1ll*j*cnt[j])%P;
	}
	memset(cnt,0,sizeof(cnt));
}
void solve2(int i){
	vi.clear();
	all.clear();
	for(int j=i;j<=n;j+=i)vi.push_back(A[j]);
	sort(vi.begin(),vi.end());
	int sz=vi.size(),f=0;
	for(int j=0;j<sz;j++){
		f++;
		if(j==sz-1||vi[j]!=vi[j+1]){
			for(auto k:fac[vi[j]]){
				all.push_back(k);
				cnt[k]+=f;
			}
			f=0;
		}
	}
	sort(all.begin(),all.end());
	sz=all.size();
	for(int j=sz-1;j>=0;j--)if(j==sz-1||all[j]!=all[j+1]){
		int x=all[j];
		cnt[x]=1ll*cnt[x]*cnt[x]%P;
		for(auto k:Q[x])add(cnt[x],P-cnt[k]);
		tmp[i]=(tmp[i]+1ll*x*cnt[x])%P;
		for(auto k:fac[x])if(cnt[k])Q[k].push_back(x);
		Q[x].clear();
	}
	for(int j=0;j<sz;j++)cnt[all[j]]=0;
}
signed main(){
#ifndef ONLINE_JUDGE
	freopen("jiedai.in","r",stdin);
#endif
	rd(n);
	for(int i=1;i<=n;i++)rd(A[i]);
//#ifndef ONLINE_JUDGE
//	n=1e5;
//	for(int i=1;i<=n;i++)A[i]=rng()%100000+1;
//#endif
	for(int i=1;i<M;i++)for(int j=i;j<M;j+=i)fac[j].push_back(i);
	for(int i=1;i<=n;i++){
		if(0);
		else if(i<=200)solve1(i);
		else solve2(i);
	}
	for(int i=n;i>=1;i--)for(int j=i+i;j<=n;j+=i)tmp[i]=(tmp[i]-tmp[j]+P)%P;
	int ans=0;
	for(int i=1;i<=n;i++)ans=(ans+1ll*i*tmp[i])%P;
	print(ans);
	return (0-0);
}