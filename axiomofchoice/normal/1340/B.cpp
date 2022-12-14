#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
//#define vector basic_string
#define fi first
#define se second
#ifndef qwq
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#endif
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N=2010; const double err=1e-11; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; typedef long double llf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} template<typename T> T sqr(const T &x){return x*x;} typedef pair<int,int> pii;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
//#define int ll
const char str[10][10]={
	"1110111",
	"0010010",
	"1011101",
	"1011011",
	"0111010",
	"1101011",
	"1101111",
	"1010010",
	"1111111",
	"1111011"
};
string s;
int t[10];
int dp[N][N];
int last[N][N];
int ans[N][N];
int top,k,n;
vector<int> b;
void disc(int a[],int n){
	b.assign(a,a+n);
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	repeat(i,0,n)
		a[i]=(lower_bound(b.begin(),b.end(),a[i])-b.begin()-1); //-1
	//orzarr(a,n);
}
void work(){
	mst(t,-1);
	repeat(i,0,10){
		int cnt=0;
		repeat(j,0,7)
			if(str[i][j]<s[j])cnt=inf;
			else cnt+=str[i][j]-s[j];
		if(cnt<1000){
			t[cnt]=i;
		}
	}
	//orzarr(t,10);
	if(top%4==2)disc(dp[top],k+2);
	top++;
	repeat(i,0,k+1)if(dp[top-1][i]!=-1)
	repeat(j,0,10)if(t[j]!=-1)
	if(i+j<=k){
		if(dp[top][i+j]<dp[top-1][i]*10+t[j]){
			dp[top][i+j]=dp[top-1][i]*10+t[j];
			last[top][i+j]=i;
			ans[top][i+j]=t[j];
		}
	}
}
signed main(){
	cin>>n>>k;
	mst(dp,-1);
	dp[0][0]=0;
	repeat(i,0,n){
		cin>>s;
		work();
	}
	//repeat(i,0,k+1)if(dp[top-1][i]!=-1)cout<<dp[top-1][i]<<' '; cout<<endl;
	//repeat(i,0,k+1)if(dp[top][i]!=-1)cout<<dp[top][i]<<' ';
	if(dp[top][k]==-1)cout<<-1,exit(0);
	vector<int> final;
	while(top){
		final.push_back(ans[top][k]);
		k=last[top][k];
		top--;
	}
	repeat_back(i,0,final.size())
		cout<<final[i];
	return 0;
}