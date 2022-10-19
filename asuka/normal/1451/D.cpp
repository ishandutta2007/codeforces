#include<bits/stdc++.h>
#define int long long
#define N
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
int t,d,k;
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld",&t);
 	while(t--){
 		scanf("%lld%lld",&d,&k);
 		int x,y,cnt = 0; x = y = 0;
 		while(x*x+y*y <= d*d){
 			cnt++;
 			if(cnt&1) x += k;
 			else y += k;
 		}
 		if(cnt%2==0) puts("Ashish");
 		else puts("Utkarsh");
 	}
	return 0;
}