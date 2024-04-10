#include<bits/stdc++.h>
#define ll long long
#define N 400015
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
using namespace std;
int n,m,q,c[N],cnt[N],f[N][23];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d%d",&n,&m);
 	rep(i,1,n) scanf("%d",&c[i]),cnt[c[i]] ^= 1;
 	rep(i,2,m) cnt[i] ^= cnt[i-1];
 	rep(j,1,19){
 		for(int i = 1;i+(1<<j)-1 <= m;++i){
 			// printf("%d %d\n",i,j);
 			f[i][j] = f[i][j-1] ^ f[i+(1<<(j-1))][j-1];
 			if(cnt[i+(1<<(j-1))-1] ^ cnt[i+(1<<j)-1]) f[i][j] ^= (1<<(j-1));
 		}
 	}
 	scanf("%d",&q);
 	while(q--){
 		int l,r,ans = 0;
 		scanf("%d%d",&l,&r);
 		per(j,0,18){
 			if(l+(1<<j) > r) continue;
 			int tmp = cnt[r] ^ cnt[l+(1<<j)-1];
 			if(tmp) ans ^= (1<<j);
 			ans ^= f[l][j];
 			l += (1<<j);
  		}
  		if(ans) printf("A");
  		else printf("B");
 	}
	return 0;
}