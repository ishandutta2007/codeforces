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
int t,n,a[N],b[N];
int check(int x){
	int lft = b[1] - x;
	rep(i,2,n){
		if(b[i]+x < a[i]) return 0;
		x = b[i] - max(0,a[i] - x);
	}
	if(x+lft >= a[1]) return 2;
	return 1;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		rep(i,1,n) scanf("%d",&a[i]);
		rep(i,1,n) scanf("%d",&b[i]);;
		int l = 0,r = b[1];
		while(l <= r){
			int mid = (l+r)>>1;
			if(check(mid) == 2){
				puts("YES");
				goto flag;
			}
			if(check(mid) == 0) l = mid+1;
			else r = mid-1;
		}
		puts("NO");
		flag: continue;
	}
	return 0;
}