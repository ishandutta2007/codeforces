#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=1000010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll dp[MAXN];
int nex[MAXN][2], prv[MAXN];
int seg[MAXN<<2], A[MAXN];
vector<pii> vec;
string S;

void Build(int id, int tl, int tr){
	if (tr-tl==1){
		seg[id]=A[tl];
		return ;
	}
	int mid=(tl+tr)>>1;
	Build(id<<1, tl, mid);
	Build(id<<1 | 1, mid, tr);
	seg[id]=max(seg[id<<1], seg[id<<1 | 1]);
}
int BS(int id, int tl, int tr, int pos, int val){
	if (tr<=pos || seg[id]<val) return -1;
	if (tr-tl==1) return tl;
	int mid=(tl+tr)>>1;
	int res=BS(id<<1, tl, mid, pos, val);
	if (res!=-1) return res;
	return BS(id<<1 | 1, mid, tr, pos, val);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>S;
	n=S.size();
	
	ll fuck=1, t=1;
	while (S.back()=='0'){
		S.pop_back();
		t++;
		if (S.empty()) kill(n)
	}
	fuck=fuck*t%mod;
	reverse(all(S));
	t=1;
	while (S.back()=='0') S.pop_back(), t++;
	fuck=fuck*t%mod;
//	debug(S)
	
	n=S.size();
	nex[n][0]=nex[n][1]=n;
	for (int i=n-1; ~i; i--){
		nex[i][0]=nex[i+1][0];
		nex[i][1]=nex[i+1][1];
		nex[i][S[i]-'0']=i;
	}
	if (nex[0][1]==n) kill(n)
	
	if (S[0]=='1') prv[0]=0;
	else prv[0]=-1;
	for (int i=1; i<n; i++){
		prv[i]=prv[i-1];
		if (S[i]=='1') prv[i]=i;
	}
	
	for (int i=0; i<n; i++) if (S[i]=='0') A[i]=i-prv[i];
	Build(1, 0, n);
	
	if (S[0]=='0'){
		dp[0]=1;
		dp[nex[0][1]]=1;
	}
	else dp[0]=1;
	
	for (int i=0; i<n-1; i++){
		dp[i]%=mod;
		if (S[i]=='0'){
			dp[nex[i][1]]+=dp[i];
			if (S[i+1]=='0') dp[i+1]+=dp[i];
			else if (prv[i]!=-1){
				int t=i-prv[i];
				int pos=BS(1, 0, n, i+1, t+1);
//				debug2(i, pos)
//				debug(t)
				if (pos!=-1){
					dp[pos]+=dp[i];
				}
			}
		}
		else{
			dp[nex[i+1][1]]+=dp[i];
			dp[nex[i][0]]+=dp[i];
		}
	}/*
	debug(dp[0])
	debug(dp[1])
	debug(dp[2])
	debug(dp[3])
	debug(dp[4])*/
//	debug(dp[5])
	
	int mx=0;
	for (int i=n-1; ~i; i--){
		if (S[i]=='1' || nex[i][1]==n || A[n-1]>=A[i]) ans=(ans + dp[i])%mod;//, debug(i);
		mx=max(mx, A[i]);
	}
	ans=ans*fuck%mod;
	cout<<ans<<"\n";
	
	
	return 0;
}
/*
00101100011100
n=14

101000
n=6

10101

*/