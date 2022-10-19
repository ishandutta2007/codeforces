#include<bits/stdc++.h>
#define int long long
#define N 200015
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
using namespace std;
int n,q,p[N],T,fac[N];
namespace BIT{
	int c[N];
	void add(int x,int v){
		for(;x<=n;x+=lowbit(x)) c[x] += v;
	}
	int query(int x){
		int res = 0;
		for(;x;x-=lowbit(x)) res += c[x];
		return res;
	}
	int query(int l,int r){
		return query(r)-query(l-1);
	}
}
using namespace BIT;
int a[21],vis[21];
void get(int cur){
	rep(i,1,15) vis[i] = 0;
	rep(i,1,15){
		int pos = cur/fac[15-i];
		rep(j,1,15){
			if(vis[j] == 0){
				if(pos == 0){
					vis[j] = 1;
					a[i] = j;
					break;
				}
				pos--;
			}
		}
		cur %= fac[15-i];
	}
	if(n < 15){
		int d = 15-n;
		rep(i,1,n){
			add(i,-p[i]);
			p[i] = a[i+d]-d;
			add(i,p[i]);
		}
	}else{
		int d = n-15;
		rep(i,1,15){
			add(i+d,-p[i+d]);
			p[i+d] = a[i]+d;
			add(i+d,p[i+d]);
		}
	}
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld%lld",&n,&q);
 	fac[0] = 1;
 	rep(i,1,15) fac[i] = fac[i-1]*i;
 	rep(i,1,n) p[i] = i,add(i,p[i]);
 	while(q--){
 		int typ,l,r;
 		scanf("%lld",&typ);
 		if(typ == 1){
 			scanf("%lld%lld",&l,&r);
 			printf("%lld\n",query(l,r));
 		}else{
 			scanf("%lld",&l);
 			T += l;
 			get(T);
 		}
 	}
	return 0;
}