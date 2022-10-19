#include<bits/stdc++.h>
#define int long long
#define N 100015
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
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
inline int gcd(int a,int b) {
    return b>0 ? gcd(b,a%b):a;
}
const int mod = 1e9 + 7;
int T,n;
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld", &n);
		int res = 0, tmp = 1;
		rep(i,2,200){
			int cur = i / gcd(tmp, i);
			res = (res + i * (n - (n / cur)) % mod ) % mod;
			// printf("%d %d %d %d\n",i, cur, n, n / cur);
			n = n / cur; tmp = tmp * cur;
			// printf("%lld %lld\n",tmp,res);
		}
		printf("%lld\n",res);
	}
	return 0;
}
// 10000000000000000
// 121645100408832000