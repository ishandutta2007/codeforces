#include<bits/stdc++.h>
#define int long long
#define N 100015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<long long,long long>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
using namespace std;
int n,k,a[N],cnt[N],ans;
int calc(int x,int div){
	int xx = x/div,left = x-xx*div;
	return left*(xx+1)*(xx+1)+(div-left)*xx*xx;
}
set<pii> s;
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld%lld",&n,&k);
 	rep(i,1,n) scanf("%lld",&a[i]);
 	rep(i,1,n){
 		int val = calc(a[i],1);
 		ans += val;
 		cnt[i] = 1;
 		s.insert(mp(calc(a[i],2)-val,i));
 	}
 	rep(i,1,k-n){
 		while(1){
 			auto cur = *s.begin();
 			s.erase(s.begin());
 			int x = cur.se;
 			ans += cur.fi;
 			if(cnt[x] < a[x]){
 				cnt[x]++;
 				s.insert(mp(calc(a[x],cnt[x]+1)-calc(a[x],cnt[x]),x));
 				break;
 			}
 		}
 	}
 	printf("%lld\n",ans);
	return 0;
}