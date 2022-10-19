#include<bits/stdc++.h>
#define int long long
#define N
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
int T,n,a,b;
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld",&n,&a,&b);
		if(b == 1) puts("Yes");
		else if(a == 1){
			puts( (n%b == 1) ? "Yes" : "No");
		} else {
			int res = 1;
			bool flag = 0;
			do{
				if((res % b) == (n % b)){
					flag = 1;
					break;
				}
				res = res * a;
			}while(res <= n);
			puts(flag ? "Yes" : "No");
		}
	}
	return 0;
}