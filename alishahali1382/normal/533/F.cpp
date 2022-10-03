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
const int MAXN = 200010, Base=10007, Mod=1e9+9;

int n, m, k, u, v, x, y, a, b;
ll tav[MAXN];
ll HT[26], H[26][MAXN];
int match[26];
int first[26];
int nxt[MAXN][26];
string s, t;
vector<int> ans;

ll Get(ll H[], int l, int r){
	ll res=(H[r-1]-H[l-1]*tav[r-l])%Mod;
	if (res<0) res+=Mod;
	return res;
}

bool check(int i){	
	memset(match, -1, sizeof(match));
	for (int j=0; j<26; j++){
		int pos=first[j];
		if (!pos) continue ;
		int jj=s[i+pos-1]-'a';
		if (match[j]!=-1 && match[j]!=jj) return 0;
		//if (match[jj]!=-1 && match[jj]!=j) return 0;
		if (Get(H[jj], i, i+m)!=HT[j]) return 0;
		//if (match[j]) continue ;
		match[j]=jj;
		match[jj]=j;
	}
	for (int j=0; j<26; j++) if (match[j]!=-1 && match[match[j]]!=-1 && match[match[j]]!=j) return 0;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	tav[0]=1;
	for (int i=1; i<MAXN; i++) tav[i]=tav[i-1]*Base%Mod;
	
	cin>>n>>m>>s>>t;
	s="."+s;
	t="."+t;
	for (int i=1; i<=n; i++){
		for (int j=0; j<26; j++) H[j][i]=H[j][i-1]*Base%Mod;
		H[s[i]-'a'][i]++;
	}
	//debug(H[0][1])
	//debug(Get(H[0], 1, 2))
	
	for (int i=1; i<=m; i++){
		for (int j=0; j<26; j++) HT[j]=HT[j]*Base%Mod;
		HT[t[i]-'a']++;
	}
	
	for (int i=m; i; i--) first[t[i]-'a']=i;
	for (int i=n; i; i--){
		for (int j=0; j<26; j++) nxt[i][j]=nxt[i+1][j];
		nxt[i][s[i]-'a']=i;
	}
	/*
	debug(check(1))
	return 0;
	*/
	for (int i=1; i<=n-m+1; i++) if (check(i)) ans.pb(i);
	cout<<ans.size()<<'\n';
	for (int i:ans) cout<<i<<' ';
	
	return 0;
}