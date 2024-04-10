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
int n,p,a[N];
bool check(int x){
	int cur = 0;
	rep(i,1,n){
		while(cur+1 <= n && a[cur+1]-i+1 <= x) cur++;
		if((cur-i+1)%p == 0) return 0;
	}
	return 1;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&p);
	rep(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1); int l = -1;
	rep(i,1,n) l = max(l,a[i]-i+1);
	int L = l,R = L+100015,ans = 0;
	while(L <= R){
		int mid = (L+R)>>1;
		// printf("%d\n",mid);
		if(check(mid)) ans = mid,L = mid+1;
		else R = mid-1;
	}
	printf("%d\n",max(0,ans-l+1));
	rep(i,l,ans) printf("%d ",i);
	return 0;
}