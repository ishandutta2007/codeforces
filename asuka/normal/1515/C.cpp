#include<bits/stdc++.h>
#define ll long long
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
#define SZ(x) ((int)x.size())
using namespace std;
int t,n,m,x,a[N],ans[N];
set<pii> S;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&t);
 	while(t--){
 		scanf("%d%d%d",&n,&m,&x);
 		rep(i,1,n) scanf("%d",&a[i]);
 		S.clear();
 		rep(i,1,m) S.insert(mp(0,i));
 		rep(i,1,n){
 			pii u = *S.begin(); S.erase(u);
 			u.fi += a[i]; ans[i] = u.se;
 			S.insert(u);
 		}
 		puts("YES");
 		rep(i,1,n) printf("%d ",ans[i]); printf("\n");
 	}
	return 0;
}