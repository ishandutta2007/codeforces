#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int n,k,x[200005],y[200005],f[30],s[200005],K;
vector<int> v[200005],e[200005];
bool b[200005];
int dfs(int x,int y){
	int ret=0;
	s[x]=1;
	for(int i=0;i<v[x].size();++i){
		int E=e[x][i];
		if(!b[E]){
			b[E]=1;
			int p=dfs(v[x][i],E);
			if(p) ret=p;
			s[x]+=s[v[x][i]];
			b[E]=0;
		}
	}
	if(s[x]==f[K-1]||s[x]==f[K-2]) return y;
	return ret;
}
bool sol(int q,int k){
	if(k<=3) return 1;
	K=k;
	int ans=dfs(q,0);
	if(!ans) return 0;
	b[ans]=1;
	if(s[x[ans]]==f[k-1]) return sol(x[ans],k-1)&&sol(y[ans],k-2);
	if(s[x[ans]]==f[k-2]) return sol(x[ans],k-2)&&sol(y[ans],k-1);
	if(s[y[ans]]==f[k-1]) return sol(y[ans],k-1)&&sol(x[ans],k-2);
	return sol(x[ans],k-1)&&sol(y[ans],k-2);
}
int main(){
	f[1]=1,f[2]=2;
	for(int i=3;i<=26;++i)f[i]=f[i-1]+f[i-2];
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		scanf("%d%d",x+i,y+i);
		v[x[i]].pb(y[i]),v[y[i]].pb(x[i]);
		e[x[i]].pb(i),e[y[i]].pb(i);
	}
	for(int i=1;i<=26;++i)if(f[i]==n)k=i;
	if(!k){
		puts("NO");
		return 0;
	}
	if(n<=3){
		puts("YES");
		return 0;
	}
	if(sol(1,k))puts("YES");
	else puts("NO");
    return 0;
}