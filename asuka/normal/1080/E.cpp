#include<bits/stdc++.h>
#define int long long
#define N 252
#define rep(i,a,n) for (register int i=a;i<=n;i++)
#define per(i,a,n) for (register int i=n;i>=a;i--)
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
using namespace std;
const int mod1 = 998244353;
const int mod2 = 19260817;
int n,m;
int G[N][N];
struct Hash{
	int h1,h2;
	Hash(){h1 = h2 = 0;}
	void operator =(int x){h1 = h2 = x;}
	inline bool operator == (Hash rhs)const{ return rhs.h1 == h1 && rhs.h2 == h2;}
	inline Hash operator *(Hash x) const{Hash res; res.h1 = h1*x.h1%mod1; res.h2 = h2*x.h2%mod2; return res;}
	inline Hash operator +(Hash x) const{Hash res; res.h1 = (h1+x.h1)>=mod1?(h1+x.h1)-mod1:(h1+x.h1); res.h2 = (h2+x.h2)>=mod2?(h2+x.h2)-mod2:(h2+x.h2); return res;}
	// Hash operator *(int x) const{Hash res; res.h1 = (h1*x)%mod1; res.h2 = (h2*x)%mod2; return res;}
	// Hash operator -(int x) const{Hash res; res.h1 = (h1-x+mod1)%mod1; res.h2 = (h2-x+mod2)%mod2; return res;}
}base,pd[29];
Hash ok[N][N][N];
int cnt[29];
int ocnt,ecnt;
void add(int x){
	if(cnt[x]&1) ocnt--,ecnt++;
	else ecnt--,ocnt++;
	cnt[x]++;
}
char s[N];
Hash D[N<<1];
int p[N<<1];
int solve(Hash *x){
	int res = 0;
	D[0] = -114; D[2*n+1] = -1;
	rep(i,1,n) D[2*i-1] = -1,D[2*i] = x[i];
	int pos = 0,mx = 0;
	rep(i,1,n+n){
		if(i < mx) p[i] = min(p[2*pos-i],mx-i);
		else p[i] = 1;
		while(D[i+p[i]] == D[i-p[i]]) p[i]++;
		if(i+p[i] > mx) mx = i+p[i],pos = i;
	}
	// rep(i,1,n+n) printf("%d ",p[i]);
	// printf("\n");
	rep(i,1,n+n){
		if((i%2==0) && x[i>>1].h1 >= mod1) continue;
		res += p[i]>>1;
	}
	return res;
}
int tot = 0;
signed main(){
	// freopen("test.txt","r",stdin);
	//freopen(".out","w",stdout);
	clock_t st = clock();
	scanf("%lld%lld",&n,&m);
	base.h1 = 29; base.h2 = 114;
	pd[0] = 1;
	rep(i,1,26) pd[i] = pd[i-1]*base;
	rep(i,1,n){
		scanf("%s",s+1);
		rep(j,1,m) G[i][j] = s[j] - 'a';
	}
	rep(i,1,n){
		rep(l,1,m){
			memset(cnt,0,sizeof cnt); 
			ocnt = ecnt = 0;
			Hash u;
			rep(r,l,m){
				u = u + pd[G[i][r]];
				add(G[i][r]);
				if((r-l+1)&1){
					if(ocnt == 1) ok[l][r][i] = u;
					else ok[l][r][i] = mod1+(++tot);
				}else if(ocnt == 0) ok[l][r][i] = u;
				else ok[l][r][i] = mod1+(++tot); 
			}
		}
	}
	int ans = 0;
	rep(l,1,m){
		rep(r,l,m){
			ans += solve(ok[l][r]);
		}
	}
	printf("%lld\n",ans);
	cerr << (double)(clock() - st) / CLOCKS_PER_SEC << endl;
	return 0;
}