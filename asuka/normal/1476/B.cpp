#include<bits/stdc++.h>
#define int long long
#define N 114
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
int t,n,k,a[N];
bool check(int sum){
	sum += a[1];
	rep(i,2,n){
		if(a[i]*100 > k*sum) return 0;
		sum += a[i];
	}
	return 1;
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld",&t);
 	rep(_,1,t){
 		scanf("%lld%lld",&n,&k);
 		rep(i,1,n) scanf("%lld",&a[i]);
 		int l = 0,r = 1e15;
 		while(l+3 < r){
 			int mid = (l+r)>>1;
 			if(check(mid)) r = mid;
 			else l = mid;
 		}
 		rep(i,l,r) if(check(i)){
 			printf("%lld\n", i);
 			break;
 		}
 	}
	return 0;
}