#include<bits/stdc++.h>
#define ll long long
#define N 1505
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
int t,m,k,a[100015];
int ans[N][N];
VI num;
vector<pii> x;
bool check(int n){
	return (n*n-(n/2)*(n/2)>=m) && (n*((n+1)/2) >= a[num[1]]);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&m,&k);
		x.clear();
		rep(i,1,k){
			scanf("%d",&a[i]);
			x.pb(mp(a[i],i));
		}

		sort(all(x)); reverse(all(x));
		num.clear(); num.pb(0);
		for(auto u:x) rep(j,1,u.fi) num.pb(u.se);
		int n = 1,l = 1;
		while(!check(n)) n++;
		printf("%d\n",n);
		rep(i,1,n)
			rep(j,1,n) ans[i][j] = 0;
		for(int i = 1;i <= n;i += 2)
			for(int j = 2;j <= n;j += 2)
				if(l <= m) ans[i][j] = num[l++];
		for(int i = 1;i <= n;i += 2)
			for(int j = 1;j <= n;j += 2)
				if(l <= m) ans[i][j] = num[l++];
		for(int i = 2;i <= n;i += 2)
			for(int j = 1;j <= n;j += 2)
				if(l <= m) ans[i][j] = num[l++];
		rep(i,1,n){
			rep(j,1,n){
				printf("%d ",ans[i][j]);
			}
			printf("\n");
		}
	}	
	return 0;
}
/*
1
25 3
12 10 3
*/