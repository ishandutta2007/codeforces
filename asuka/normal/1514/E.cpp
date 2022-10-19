#include<bits/stdc++.h>
#define ll long long
#define N 105
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
int query(int u,int v){
	printf("1 %d %d\n",u,v);
	fflush(stdout);
	int x; scanf("%d",&x);
	return x;
}
VI solve(int l,int r){
	VI tmp;
	if(l == r){
		tmp.pb(l);
		return tmp;
	}
	VI a,b; int mid = (l+r)>>1;
	a = solve(l,mid); b = solve(mid+1,r);
	int sa,sb; sa = sb = 0;
	while(sa < a.size() && sb < b.size()){
		if(query(a[sa],b[sb])) tmp.pb(a[sa++]);
		else tmp.pb(b[sb++]);
	}
	while(sa < a.size()) tmp.pb(a[sa++]);
	while(sb < b.size()) tmp.pb(b[sb++]);
	return tmp;
}
bool dp[N][N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		rep(i,0,n) rep(j,0,n) dp[i][j] = 0;
		rep(i,0,n-1) dp[i][i] = 1;
		VI a = solve(0,n-1); int p = n-1;
		rep(i,1,n-1) dp[a[i-1]][a[i]] = 1;
		per(i,0,n-1){
			p = min(p,i);
			while(p-1 >= 0){
				printf("%d %d %d ",2,a[i],p);
				rep(j,0,p-1)
					printf("%d ",a[j]);
				printf("\n");
				fflush(stdout);
				int x; scanf("%d",&x);
				if(x) dp[a[i]][a[p-1]] = 1,p--;
				else break;
			}
		}
		rep(k,0,n-1) rep(i,0,n-1) rep(j,0,n-1){
			dp[i][j] |= dp[i][k]&dp[k][j];
		}
		printf("3\n");
		rep(i,0,n-1){
			rep(j,0,n-1)
				printf("%d",dp[i][j]);
			printf("\n");
		}
		fflush(stdout);
		int x; scanf("%d",&x);
		if(x == -1) exit(0);
	}
	return 0;
}