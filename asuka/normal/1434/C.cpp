#include<bits/stdc++.h>
#define int long long
#define N
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int t,a,b,c,d,loop;
int f(int x){
	return -1*(-a*x+x*(x-1)/2*loop*b);
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(a > b*c) printf("-1\n");
		else{
			int ans = a;
			loop = d;
			int k = (1.0*a/(1.0*loop*b/2) +1 )/2.0;
			ans = max({ans,f(k),f(k+1),f(k-1)});
			/*
			 -a + d*1*b -a + loop*2*b -a +loop*3*b
			 k+1a f(k+1) = -a(k+1) + k*(k+1)/2*loop*b
			 f(k) = -ak + k*(k-1)/2*loop*b = -ak + loop*b/2*k^2 - loop*b/2*k
			 = loop*b/2*k^2 + (-a - loop*b/2)*k
			 = k*(loop*b/2*k - a - loop*b/2) k = a/(loop*b/2) + 1
			*/
			printf("%lld\n",ans);
		}
	}
	return 0;
}
/*
c = 7;
d = 6;
1   2   3   4   5   6
-a  +b  +b  +b  +b  +b  +b  +b
        				-a  +b  +b  +b  +b  +b  +b  +b
            									-a  +b  +b  +b  +b  +b  +b  +b
            															-a  +b  +b  +b  +b  +b  +b  +b
									  
else    +b
[x,x+c]
*/