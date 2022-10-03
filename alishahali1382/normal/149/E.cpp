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
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

int n, m, q, u, v, x, y, t, a, b, ans;
int pref[1010];
int f[1010];
string S, T;

bool solve(){
	memset(pref, 63, sizeof(pref));
	memset(f, 0, sizeof(f));
	cin>>T;
	m=T.size();
	if (m<=1 || m>n) return 0;
	T="."+T;
	
	f[1]=0;
	int k=0;
	for (int i=2; i<=m; i++){
		while (k && T[k+1]!=T[i]) k=f[k];
		f[i]=k+=(T[k+1]==T[i]);
		//debug2(i, f[i])
	}
	
	//debug("damn")
	
	k=0;
	for (int i=1; i<=n; i++){
		while (k && T[k+1]!=S[i]) k=f[k];
		k+=(T[k+1]==S[i]);
		pref[k]=min(pref[k], i);
		//debug2(i, k)
		if (k==m) k=f[k];
	}
	
	for (int i=m; i; i--) pref[i]=min(pref[i], pref[i+1]);
	pref[0]=inf;
	
	//for (int i=1; i<=m; i++) cerr<<pref[i]<<" \n"[i==m];
	//debug("fuck")
	
	f[m]=m+1;
	k=m+1;
	for (int i=m-1; i; i--){
		//debug2(i, k)
		while (k<=m && T[i]!=T[k-1]) k=f[k];
		f[i]=k-=(T[i]==T[k-1]);
		//debug2(i, f[i])
	}
	//debug("shit")
	k=m+1;
	for (int i=n; i; i--){
		//debug2(i, k)
		while (k<=m && S[i]!=T[k-1]) k=f[k];
		k-=(S[i]==T[k-1]);
		if (pref[k-1]<i) return 1;
		if (k<=1) k=f[1];
	}
	
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>S>>q;
	n=S.size();
	S="."+S;
	while (q--) ans+=solve();
	cout<<ans<<'\n';
	
	return 0;
}
/*

ABCBABA
1
ABBA


BBABAABAABBBBAB
10
BBABAABAABBA
A
BBAA
AAAABB
AA
AABB
ABBBBABAABA
ABB
AAABABBAAABAAAA
BABAA



BBABAABAABBBBAB
1
BBABAABAABBA


*/