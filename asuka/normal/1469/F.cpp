#include<bits/stdc++.h>
#define ll long long
#define N 400015
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
ll a[N],l[N],n,k;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld%lld",&n,&k);
 	a[1] = 1; a[2] = -1; int st = 1,ans = 1919810;
 	ll res = 0;
 	rep(i,1,n) scanf("%lld",&l[i]);
 	sort(l+1,l+n+1,greater<ll>());
 	rep(i,1,400000){
 		res += a[i];
 		a[i+1] += a[i];
 		if(res + a[i+1] >= k) ans = min(ans,i);
 		while(a[i] > 0 && st <= n){
 			int x = (l[st]-1)/2,y = l[st]-1-x;
 			res --; a[i] --;
 			a[i+2] ++; a[i+2+x] --;
 			a[i+2] ++; a[i+2+y] --; 
 			st++;
 		}
 	}
 	if(ans == 1919810) puts("-1");
 	else printf("%d\n",ans);
	return 0;
}