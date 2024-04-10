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
int t,n,l,r,a[N],cnt[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&t);
 	while(t--){
 		scanf("%d%d%d",&n,&l,&r);
 		rep(i,1,n) scanf("%d",&a[i]);
 		rep(i,1,n) cnt[i] = 0;
 		rep(i,1,l) cnt[a[i]]++;
 		rep(i,l+1,n) cnt[a[i]]--;
 		int lft = abs(r-l),turn = lft/2,col = 0;lft /= 2;
 		if(l > r){
 			rep(i,1,n) {
	 			while(lft > 0 && cnt[i] > 1) lft--,cnt[i] -= 2;
	 		}
 		}else{
 			rep(i,1,n) {
	 			while(lft > 0 && cnt[i] < -1) lft--,cnt[i] += 2;
	 		}
 		}
 		rep(i,1,n) col += abs(cnt[i]);
 		// rep(i,1,n) assert(abs(cnt[i])==1)
 		printf("%d\n",(col/2)+turn);
 	}
	return 0;
}