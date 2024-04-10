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
int n,a[N];
set<pair<int,int>> s;
inline int highbit(int x){return 31-__builtin_clz(x);}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld",&n);
 	rep(i,1,n) scanf("%lld",&a[i]);
 	rep(l,1,n){
 		int r = l+1,sum = 0,lim = (1<<(highbit(a[l])+1));
 		while(r < n && sum < lim){
 			sum += a[r++];
 			if((a[l]^a[r]) == sum) s.insert(mp(l,r));
 		}
 	}
 	reverse(a+1,a+n+1);
 	rep(l,1,n){
 		int r = l+1,sum = 0,lim = (1<<(highbit(a[l])+1));
 		while(r < n && sum < lim){
 			sum += a[r++];
 			if((a[l]^a[r]) == sum) s.insert(mp(n-r+1,n-l+1));
 		}
 	}
 	printf("%lld\n",(int)s.size());
	return 0;
}