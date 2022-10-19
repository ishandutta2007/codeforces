#include<bits/stdc++.h>
#define int long long
#define N 500015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<long long>
#define all(x) x.begin(),x.end()
using namespace std;
int n,k,a[N],d[N],ans;
VI b;
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld%lld",&n,&k);
 	rep(i,1,n) scanf("%lld",&a[i]),a[i] += n-i+1;
 	b.pb(0);rep(i,1,k){
 		int t;scanf("%lld",&t);b.pb(t);
 	}
 	a[0] = 0;a[n+1] = inf;
 	b.pb(n+1);
 	// rep(i,1,n) printf("%d ",a[i]);
 	// puts("");
 	int sz = b.size();
 	rep(i,0,sz-2){
 		int l = b[i],r = b[i+1];
 		if(a[r] < a[l]){
 			puts("-1") ; return 0;
 		}
 		int len = (r-1)-(l+1)+1;
 		rep(p,1,len) d[p] = inf;
 		d[0] = 0;
 		rep(j,l+1,l+len){
 			if(a[j] < a[l] || a[r] < a[j]) continue;
 			int pos = upper_bound(d+1,d+len+1,a[j])-d;
 			d[pos] = a[j];
 	//		rep(p,1,len) cout << d[p] << ' ';
 	//		cout << endl;
 		}
 		int cur = len;
 		while(d[cur] == inf) cur--;
 	//	cout << "fvck" << cur << endl;
 		ans += len-cur;
 	}
 	// rep(i,1,n) if(d[i] <= 0){
 	// 	puts("-1") ; return 0;
 	// }
 	printf("%lld\n",ans);
	return 0;
}