#include<bits/stdc++.h>
#define ll long long
#define N 100015
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
using namespace std;
int t,n;
ll k;
VI a;
set<int> S;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%lld",&n,&k); a.clear();
		k--;
		if((n-1) <= 62 && k >= (1ll<<(n-1))){
			puts("-1");
			continue;
		}
		rep(i,1,n){
			int j = i+1;
			while(j <= n && n-j <= 62 && k >= (1ll<<(n-j))){
				k -= (1ll<<(n-j));
				j++;
			}
			per(x,i,j-1) a.pb(x);
			i = j-1;
		}
		for(auto x:a) printf("%d ",x);
		printf("\n");
	}
	return 0;
}