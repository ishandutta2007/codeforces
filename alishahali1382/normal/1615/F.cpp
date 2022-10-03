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
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=10010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
ll F[MAXN], I[MAXN], ans;
string S, T;
int cntS[MAXN][3], cntT[MAXN][3];

ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}
ll nCr(int n, int r){
	if (r<0 || r>n) return 0;
	return F[n]*I[r]%mod*I[n-r]%mod;
}
ll Solve(int x, int y, int k){ // 0<=a<=x  0<=b<=y  a-b=k
	// a+(y-b) = k+y
	return nCr(x+y, k+y);
}
int Main(){
	cin>>n>>S>>T;
	for (int i=0; i<n; i++) if (i&1){
		if (S[i]!='?') S[i]='0'+'1'-S[i];
		if (T[i]!='?') T[i]='0'+'1'-T[i];
	}
//	debug(S)
//	debug(T)
	for (int i=1; i<=n; i++){
		memcpy(cntS[i], cntS[i-1], sizeof(cntS[i]));
		memcpy(cntT[i], cntT[i-1], sizeof(cntT[i]));
		cntS[i][S[i-1]=='?'?2:S[i-1]-'0']++;
		cntT[i][T[i-1]=='?'?2:T[i-1]-'0']++;
	}
	ans=0;
	for (int i=1; i<n; i++){
		for (int k=-i; k<=i; k++){
			ll res=abs(k);
			res=res*Solve(cntS[i][2], cntT[i][2], k+cntT[i][1]-cntS[i][1])%mod;
			res=res*Solve(cntS[n][2]-cntS[i][2], cntT[n][2]-cntT[i][2], -k+(cntT[n][1]-cntT[i][1])-(cntS[n][1]-cntS[i][1]))%mod;
//			debug2(k, res)
			ans+=res;
		}
	}
	ans%=mod;
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	I[MAXN-1]=powmod(F[MAXN-1], mod-2);
	for (int i=MAXN-1; i; i--) I[i-1]=I[i]*i%mod;
//	debug(nCr(5, 2))
	int T;
	cin>>T;
	while (T--) Main();
	
	return 0;
}
/*
1
2
00
11

*/