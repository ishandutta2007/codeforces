#include<bits/stdc++.h>
#define int long long
#define N 4005
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
int n,m,k,l[N],r[N],d[N],ans;
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld%lld%lld",&n,&m,&k);
 	rep(i,1,m) scanf("%lld%lld",&l[i],&r[i]);
 	rep(R,k,n){
 		int L = R-k+1,cur = 0;
 		rep(i,0,n) d[i] = 0;
 		rep(i,1,m){
 			int sec = max(min(R,r[i])-max(L,l[i])+1,0ll);
 			cur += sec;
 			if(r[i]-l[i]+1 > sec){
 				d[l[i]+sec]++; d[l[i]+k]--;
 				d[r[i]+1]--; d[r[i]+k-sec+1]++;
 			}
 		}
 		int sum = 0;
 		rep(i,0,n){
 			sum += d[i];
 			cur += sum;
 			ans = max(ans,cur);
 		}
 	}
 	printf("%lld\n",ans);
	return 0;
}