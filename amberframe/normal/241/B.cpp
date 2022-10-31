#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>

using namespace std;
typedef pair<int,int> mp;
typedef long long LL;
#define pb push_back
const int maxn = 50005;
const LL mod = 1e9+7;

int n,a[maxn],rt=1;LL m,ans;
int bac1[32][2];
int bac2[32][2];
int val[maxn*32];
int son[maxn*32][2];
int cnt[maxn*32],tot=1;
vector<mp> pr,tmp;
void insert(int &root,int num,int bit) {
	if (!root) root=++tot;
	int p=(num>>bit)&1;cnt[root]++;
	if (bit<0) {val[root]=num;return ;}
	insert(son[root][p],num,bit-1);
}
void dfs(int root,int bac[32][2]) {
	if (!root) return ;
	if (!son[root][0]&&!son[root][1]) {
		int num=val[root],_cnt=cnt[root];
		for (int j=30;j>=0;j--)
			bac[j][(num>>j)&1]+=_cnt;
		return ;
	}
	dfs(son[root][0],bac);
	dfs(son[root][1],bac);
}
void update() {
	for (int i=0;i<pr.size();i++) {
		int ls1=son[pr[i].first][0];
		int rs1=son[pr[i].first][1];
		int ls2=son[pr[i].second][0];
		int rs2=son[pr[i].second][1];
		memset(bac1,0,sizeof bac1);
		memset(bac2,0,sizeof bac2);
		dfs(ls1,bac1);dfs(rs2,bac2); 
		for (int j=0;j<31;j++)
			ans+=(1ll<<j)*bac1[j][0]*bac2[j][1]+(1ll<<j)*bac1[j][1]*bac2[j][0];
		if (pr[i].first==pr[i].second) continue;
		memset(bac1,0,sizeof bac1);
		memset(bac2,0,sizeof bac2);
		dfs(ls2,bac1);dfs(rs1,bac2); 
		for (int j=0;j<31;j++)
			ans+=(1ll<<j)*bac1[j][0]*bac2[j][1]+(1ll<<j)*bac1[j][1]*bac2[j][0];
	}	
}
LL query() {
	LL res=0ll;
	for (int i=0;i<pr.size();i++) {
		int ls1=son[pr[i].first][0];
		int rs1=son[pr[i].first][1];
		int ls2=son[pr[i].second][0];
		int rs2=son[pr[i].second][1];
		if (ls1&&rs2) res+=(LL)cnt[ls1]*cnt[rs2]; 
		if (pr[i].first==pr[i].second) continue;
		if (ls2&&rs1) res+=(LL)cnt[ls2]*cnt[rs1];
	}
	return res;
}
void trans0() {
	for (int i=0;i<pr.size();i++) {
		int ls1=son[pr[i].first][0];
		int rs1=son[pr[i].first][1];
		int ls2=son[pr[i].second][0];
		int rs2=son[pr[i].second][1];
		if (ls1&&ls2) tmp.pb(mp(ls1,ls2));
		if (rs1&&rs2) tmp.pb(mp(rs1,rs2));
	}
	pr.clear();swap(pr,tmp);
}
void trans1() {
	for (int i=0;i<pr.size();i++) {
		int ls1=son[pr[i].first][0];
		int rs1=son[pr[i].first][1];
		int ls2=son[pr[i].second][0];
		int rs2=son[pr[i].second][1];
		if (ls1&&rs2) tmp.pb(mp(ls1,rs2));
		if (pr[i].first==pr[i].second) continue;
		if (ls2&&rs1) tmp.pb(mp(ls2,rs1));
	}	
	pr.clear();swap(pr,tmp);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("friends.in","r",stdin);
		freopen("friends.out","w",stdout);
	#endif
	scanf("%d %lld",&n,&m);
	for (int i=1;i<=n;i++) 
		scanf("%d",&a[i]),insert(rt,a[i],30);
	LL num=0;pr.pb(mp(1,1)); 
	for (int i=30;i>=0;i--) {
		LL res=query();
		if (res>m) {trans1();num|=1ll<<i;}
		else {update();trans0();m-=res;}
	}
	ans+=m*num;ans%=mod;
	printf("%I64d",ans);
	return 0;
}