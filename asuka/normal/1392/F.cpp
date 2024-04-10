#include<bits/stdc++.h>
#define ll long long
#define N 1000015
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
int n;
ll h[N],ans[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n) scanf("%lld",&h[i]);
	ll S = 0,T = (1ll*n*(n-1))/2;
	rep(i,1,n) S += h[i];
	rep(i,1,n) ans[i] = (i-1) + (S-T)/n + (((i-1) < (S-T)%n) ? 1:0);
	rep(i,1,n) printf("%lld ",ans[i]);
	return 0;
}