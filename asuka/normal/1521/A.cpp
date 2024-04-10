#include<bits/stdc++.h>
#define ll long long
#define N
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
int t;
ll A,B;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld",&A,&B);
		if(B == 1) puts("NO");
		else{
			puts("YES");
			if(B == 2){
				printf("%lld %lld %lld\n",A,3*A,4*A);
			}else{
				printf("%lld %lld %lld\n",A,(B-1)*A,A*B);
			}
		}
	}
	return 0;
}