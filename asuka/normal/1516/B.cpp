#include<bits/stdc++.h>
#define ll long long
#define N 2005
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
int t,n,pre[N],suf[N],a[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&t);
 	while(t--){
 		scanf("%d",&n);
 		bool flag = 0;
 		rep(i,1,n) scanf("%d",&a[i]);
 		rep(i,0,n+1) pre[i] = suf[i] = 0;
 		rep(i,1,n) pre[i] = pre[i-1]^a[i];
 		rep(i,1,n-1) if(pre[i] == (pre[n]^pre[i])) flag = 1;
 		rep(l,1,n){
 			rep(r,l+1,n-1){
 				if(pre[l] == (pre[r]^pre[l]) && pre[l] == (pre[n]^pre[r])) flag = 1;
 			}
 		}
 		if(flag) puts("YES");
 		else puts("NO");
 	}
	return 0;
}