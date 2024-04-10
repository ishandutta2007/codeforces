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
int n,a[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1); ll ans = 0; int cnt = 0;
	rep(i,2,n) if(a[i] == a[i-1]) cnt++;
	rep(i,2,n) if(a[i] == 0 && a[i-1] == 0) cnt = 114514;
	if(cnt >= 2){
		puts("cslnb");
		return 0;
	}
	a[0] = -114514;
	if(cnt == 1){
		rep(i,2,n){
			if(a[i] == a[i-1] && a[i-2] == a[i-1]-1) {puts("cslnb"); return 0;}
			if(a[i] == a[i-1]) a[i-1]--,ans++;
		}
	}
	rep(i,1,n) ans += a[i]-(i-1);
	ans++;
	if(ans&1) puts("cslnb");
	else puts("sjfnb");
	return 0;
}