#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

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

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const ll Base=10007, Mod=998244353;
const int MAXN = 1000010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
ll HL[MAXN], HR[MAXN];
ll tav[MAXN];
bool ok[MAXN];
string S;

ll GetL(int l, int r){ // [l, r]
	ll res=(HL[r]-HL[l-1]*tav[r-l+1])%Mod;
	if (res<0) res+=Mod;
	return res;
}
ll GetR(int l, int r){ // [l, r]
	ll res=(HR[l]-HR[r+1]*tav[r-l+1])%Mod;
	if (res<0) res+=Mod;
	return res;
}

void Solve(){
	cin>>S;
	n=S.size();
	S="."+S;
	ok[0]=1;
	for (int i=1; i<=n; i++) ok[i]=ok[i-1] && (S[i]==S[n+1-i]);
	if (ok[n]){
		for (int i=1; i<=n; i++) cout<<S[i];
		cout<<'\n';
		return ;
	}
	HL[0]=0;
	for (int i=1; i<=n; i++) HL[i]=(HL[i-1]*Base + S[i])%Mod;
	HR[n+1]=0;
	for (int i=n; i; i--) HR[i]=(HR[i+1]*Base + S[i])%Mod;
	
	pair<int, pii> ans={-1, {0, -1}};
	
	// even
	for (int i=1; i<n; i++){
		int dwn=0, up=min(i, n-i)+1;
		while (up-dwn>1){
			int mid=(dwn+up)>>1;
			int l=i-mid+1, r=i+mid;
			if (GetL(l, r)==GetR(l, r)) dwn=mid;
			else up=mid;
		}
		int l=i-dwn+1, r=i+dwn;
		if (l-1>n-r && ok[n-r]) ans=max(ans, {r-l+1 + 2*(n-r), {l, r}});
		if (l-1<=n-r && ok[l-1]) ans=max(ans, {r-l+1 + 2*(l-1), {l, r}});
	}
	
	// odd
	for (int i=1; i<=n; i++){
		int dwn=0, up=min(i-1, n-i)+1;
		while (up-dwn>1){
			int mid=(dwn+up)>>1;
			int l=i-mid, r=i+mid;
			if (GetL(l, r)==GetR(l, r)) dwn=mid;
			else up=mid;
		}
		int l=i-dwn, r=i+dwn;
		if (l-1>n-r && ok[n-r]) ans=max(ans, {r-l+1 + 2*(n-r), {l, r}});
		if (l-1<=n-r && ok[l-1]) ans=max(ans, {r-l+1 + 2*(l-1), {l, r}});
	}
	string T;
	int len=(ans.first-(ans.second.second-ans.second.first+1))/2;
	/*
	debugp(ans.second)
	debug(ans.first)
	debug(len)
	*/
	for (int i=1; i<=len; i++) T+=S[i];
	for (int i=ans.second.first; i<=ans.second.second; i++) T+=S[i];
	for (int i=n-len+1; i<=n; i++) T+=S[i];
	cout<<T<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	tav[0]=1;
	for (int i=1; i<MAXN; i++) tav[i]=tav[i-1]*Base%Mod;
	
	int Test;
	cin>>Test;
	while (Test--) Solve();
	
	return 0;
}
/*
1
acbba

*/