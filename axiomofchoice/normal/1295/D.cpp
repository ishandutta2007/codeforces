#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define lll __int128
typedef long long ll; const int inf=2e9;
typedef double lf; const lf err=1e-11; typedef long double llf;
typedef pair<int,int> pii;
#define repeat(i,a,b) for(int i=(a),__=(b);i<__;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,__=(a);i>=__;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq (cerr<<"qwq"<<endl)
#define orz(x) (cerr<<#x": "<<x<<endl)
#define orzarr(a,n) cerr<<#a": "; repeat(I,0,n)cerr<<(a)[I]<<" "; cerr<<endl;
#define orzeach(a) cerr<<#a": "; for(auto i:a)cerr<<i<<" "; cerr<<endl;
#define fi first
#define se second
ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;}
mt19937 rnd(time(0));
//tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> t; //
const int N=100010;
const int mod=(1?1000000007:998244353);
#define int ll
int euler_phi(int n){
	int m = int(sqrt(n+0.5));
	int ans = n;
	for(int i = 2; i <= m; i++)
	if(n % i == 0){
		ans = ans / i * (i-1);
		while(n % i == 0)n /= i;
	}
	if(n > 1)ans = ans / n * (n-1);
	return ans;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin>>t;
	while(t--){
		int a,m; cin>>a>>m;
		int g=__gcd(a,m);
		a/=g,m/=g;
		cout<<euler_phi(m)<<endl;
	}
	return 0;
}