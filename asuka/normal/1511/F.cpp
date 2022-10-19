#include<bits/stdc++.h>
#define ll long long
#define N
#define mod 998244353
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define end qwq
using namespace std;
int n,m;
namespace Trie{
	int tr[405][26],rt = 0,end[405],cnt;
	void insert(char *s){
		int cur = rt;
		for(int i = 1;s[i];++i){
			if(!tr[cur][s[i]-'a']) tr[cur][s[i]-'a'] = ++cnt;
			cur = tr[cur][s[i]-'a'];
		}
		end[cur] = 1;
	}
}
using namespace Trie;
struct matrix{
	int a[205][205];
	matrix(){memset(a,0,sizeof a);}
	int* operator[](int i){return a[i];}
	matrix operator*(matrix lhs) const{
		matrix res;
		rep(i,0,200) rep(j,0,200) rep(k,0,200){
			res[i][k] = (res[i][k] + 1ll*a[i][j]*lhs[j][k])%mod;
		}
		return res;
	}
}base;
queue<pii> Q; 
map<pii,int> id;
int tot;
int get(pii x){
	if(x.fi > x.se) swap(x.fi,x.se);
	if(id.count(x) > 0) return id[x];
	else{
		id[x] = tot;
		Q.push(x);
		return tot++;
	}
}
matrix qpow(matrix a,int b){
	matrix res;
	rep(i,0,200) res[i][i] = 1;
	while(b){
		if(b&1) res = res*a;
		a = a*a; b >>= 1;
	}
	return res;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		char s[105];
		scanf("%s",s+1);
		insert(s);
	}
	// printf("%d\n",cnt);
	get(mp(0,0));
	while(!Q.empty()){
		pii u = Q.front(); Q.pop();
		int x = u.fi,y = u.se,cid = get(mp(x,y));
		// printf("%d %d %d\n",x,y,cid);
		rep(i,0,25){
			int tx = tr[x][i],ty = tr[y][i];
			if(!tx || !ty) continue;
			base[cid][get(mp(tx,ty))]++;
			if(end[tx]) base[cid][get(mp(0,ty))]++;
			if(end[ty]) base[cid][get(mp(0,tx))]++;
			if(end[tx] && end[ty]) base[cid][get(mp(0,0))]++;
		}
	}
	base = qpow(base,m);
	printf("%d\n",base[0][0]);
	return 0;
}