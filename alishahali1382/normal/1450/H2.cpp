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
const int mod=998244353, inv2=(mod+1)/2;
const int MAXN=400010, LOG=20;

ll n, m, k, u, v, x, y, t, X, Y, ans;
char A[MAXN];
ll F[MAXN], I[MAXN], tav[MAXN];

ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}
ll nCr(ll n, ll r){
	if (r<0 || r>n) return 0;
	return F[n]*I[r]%mod*I[n-r]%mod;
}

struct Solver{
	ll n, r, ans;
	Solver(){
		n=r=0;
		ans=1;
	}
	void SetN(int N){
		// N>=0
		if (r<0){
			n=N;
			return ;
		}
		if (N==0){
			n=N;
			ans=(r>=0);
			return ;
		}
		while (n<N){
			ans=(2*ans - nCr(n, r))%mod;
			n++;
		}
		while (N<n){
			n--;
			ans=(ans + nCr(n, r))*inv2%mod;
		}
	}
	void SetR(int R){
		if (R<0){
			ans=0;
			r=-1;
			return ;
		}
		if (r==-1){
			r=0;
			ans=1;
		}
		while (r<R){
			r++;
			ans=(ans + nCr(n, r))%mod;
		}
		while (R<r){
			ans=(ans - nCr(n, r))%mod;
			r--;
		}
	}
	ll get(int p){
		p&=1;
		if (r<0) return 0;
		if (!n) return (p==0);
		ll res=(ans + nCr(n-1, r))*inv2%mod;
		if ((r&1)^p) res=(res-nCr(n-1, r))%mod;
//		cerr<<"get "<<n<<" "<<r<<"  "<<p<<": "<<res<<"\n";
//		debug(ans)
		return res;
	}
} S1, S2;

void Solve(){
	ans=0;
	if (!X){
		if ((n-Y)%2==0) ans=abs(n-Y);
		return ;
	}
	
	S1.SetN(X);
	S1.SetR(n-Y);
	ans=(n-Y)*S1.get(n-Y)%mod;
	
	S1.SetN(X-1);
	S1.SetR(n-Y-1);
	ans=(ans - X*S1.get(n-Y+1))%mod;
	
	S2.SetN(X);
	S2.SetR(n-Y);
	ans=(ans + (Y-n)*(tav[X-1]-S2.get(n-Y-2)))%mod;
	
	
	if (X>1){
		int p=n-Y+1;
		S2.SetN(X-1);
		S2.SetR(p-1);
		ans=(ans + X*(tav[X-2]-S2.get(p)))%mod;
	}
	else{
		if (n-Y+1<=0 && (n-Y+1)%2==0) ans=(ans + X)%mod;
	}
	
}

void print(){
	if (ans<0) ans+=mod;
	cout<<ans*powmod(2, mod-1-X)%mod<<"\n";
//	debug(ans)
//	cerr<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F[0]=tav[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod, tav[i]=tav[i-1]*2%mod;
	I[MAXN-1]=powmod(F[MAXN-1], mod-2);
	for (int i=MAXN-1; i; i--) I[i-1]=I[i]*i%mod;
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		if (A[i]=='?') X++;
		else{
			if (i&1) A[i]='w'+'b'-A[i];
			Y+=(A[i]=='w');
		}
	}
	n>>=1;
	
	Solve();
	print();
	while (m--){
		cin>>x;
		if (A[x]=='?') X--;
		else Y-=(A[x]=='w');
		cin>>A[x];
		if (A[x]!='?' && (x&1)) A[x]='b'+'w'-A[x];
		if (A[x]=='?') X++;
		else Y+=(A[x]=='w');
		Solve();
		print();	
	}
	
	return 0;
}
/*
8 0
?bw?b???

4 4
bb?b
1 w
2 ?
2 w
2 ?

4 2
bb?b
1 w
2 ?


4 0
bb?b

4 0
w??b


*/