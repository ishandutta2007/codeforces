#include<bits/stdc++.h>
#define ll long long
#define N 200015
#define M 1<<10
#define lowbit(i) ((i)&(-i))
using namespace std;
int n,m,k,maxn,p[N],l[N],r[N];
int sm[M],st[M],vis[M],f[2][M],val[M]; 
vector<int> mem[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= n;++i) {
		scanf("%d%d",&l[i],&r[i]);
		p[++maxn] = l[i];
		p[++maxn] = r[i]+1;
	}
	sort(p+1,p+maxn+1);
	maxn = unique(p+1,p+maxn+1)-p-1;
	for(int i = 1;i <= n;++i){
		int le = lower_bound(p+1,p+maxn+1,l[i])-p,
		ri = lower_bound(p+1,p+maxn+1,r[i]+1)-p;
		for(int j = le;j < ri;++j)
			mem[j].push_back(i);
	}
	int now = 0,next = 1;
	for(int i = 1;i < maxn;++i){
		int s0 = mem[i-1].size(),s1 = mem[i].size();
		fill(f[next],f[next]+(1<<s1),0);
		fill(sm,sm+(1<<s1),0);
		fill(st,st+(1<<s0),0);
		fill(val,val+(1<<s0),-1);
		int tp = 0;
		for(int j = 0;j < s1;++j)
			for(int k = 0;k < s0;++k)
				if(mem[i-1][k]==mem[i][j])
					sm[1<<j] = (1<<k),vis[k] = i;
		for(int j = 0;j < s0;++j)
			if(vis[j]!=i)
				st[1<<tp] = (1<<j),tp++;
		for(int j = 0;j < (1<<tp);++j)
			st[j] = st[lowbit(j)]|st[j^lowbit(j)];
		for(int j = 0;j < (1<<s1);++j){
			sm[j] = sm[lowbit(j)]|sm[j^lowbit(j)];
			if(val[sm[j]] < 0){
				for(int k = 0;k < (1<<tp);++k){
					val[sm[j]] = max(val[sm[j]],f[now][sm[j]|st[k]]);
				}
			}
			f[next][j] = val[sm[j]];
			if(__builtin_popcount(j)&1) f[next][j] += p[i+1]-p[i];
		}
		now ^= 1;next ^= 1;
	}
	int res = 0;
	for(int i = 0;i < (1<<mem[maxn-1].size());++i)
		res = max(res,f[now][i]);
	printf("%d\n",res);
	return 0;
}