#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=510; typedef long long ll; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
#define int ll
int a[N],b[N],k;
bitset<N*2> dp,dp2;
void push(int l,int r){
	if(l>r)return;
	dp2=0;
	repeat(i,l,r+1)
		dp2|=dp<<i;
	dp|=dp2;
	dp|=dp>>k;
}
void solve(){
	int n,sa=0,sb=0,ans=0;
	cin>>n>>k;
	repeat(i,0,n)cin>>a[i]>>b[i],sa+=a[i],sb+=b[i];
	dp=1;
	repeat(i,0,n){
		push(max(1ll,k-b[i]),min(k-1,a[i]));
	}
	ans=sa/k+sb/k;
	repeat(i,0,k+1)
	if(dp[i]){
		int j=k-i;
		if(sa>=i && sb>=j)
			ans=max(ans,(sa-i)/k+(sb-j)/k+1);
	}
	cout<<ans<<endl;
}
signed main(){
	int T=1; //cin>>T;
	while(T--)solve();
	return 0;
}