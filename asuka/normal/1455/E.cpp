#include<bits/stdc++.h>
#define int long long
#define N
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
using namespace std;
int t,x[5],y[5],p[5];
int solve(int a[5],int len){
	a[3] -= len; a[4] -= len;
	sort(a+1,a+5);
	return a[4]-a[1]+a[3]-a[2];
}
int solve(int len){
	//printf("len: %d %d %d\n",len,solve(x,len),solve(y,len));
	int a[5],b[5];
	a[1] = x[p[3]]; a[2] = x[p[4]]; a[3] = x[p[1]]; a[4] = x[p[2]]; 
	b[1] = y[p[1]]; b[2] = y[p[3]]; b[3] = y[p[2]]; b[4] = y[p[4]]; 
	return solve(a,len)+solve(b,len);
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld",&t);
 	while(t--){
 		rep(i,1,4) scanf("%lld%lld",&x[i],&y[i]);
 		rep(i,1,4) p[i] = i;
 		 int ans = inf;
 		do{
	 		int l = 0,r = 1e9;
	 		while(l+3 < r){
	 			int m1 = l+(r-l)/3,m2 = r-(r-l)/3;
	 			if(solve(m1) < solve(m2)) r = m2;
	 			else l = m1;
	 		}
	 		rep(i,l,r) ans = min(ans,solve(i));//,printf("%lld %lld\n",i,solve(i));
 		}while(next_permutation(p+1,p+5));
 		printf("%lld\n",ans);
 	}
	return 0;
}
/*
1
2 5
2 8
4 0
9 0
*/