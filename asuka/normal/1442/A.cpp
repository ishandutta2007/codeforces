#include<bits/stdc++.h>
#define ll long long
#define N 30005
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
using namespace std;
int t,a[N],d[N],n;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&t);
 	while(t--){
 		scanf("%d",&n);
 		rep(i,1,n) scanf("%d",&a[i]);
 		rep(i,1,n) d[i] = a[i]-a[i-1];
 		ll sum = 0;
 		rep(i,2,n) if(d[i] < 0) sum += -1ll*d[i];
 		if(d[1] >= sum) puts("YES");
 		else puts("NO");
 	}
	return 0;
}