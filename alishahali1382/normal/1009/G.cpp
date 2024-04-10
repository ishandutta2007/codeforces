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
const int MAXN=100010;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
int U[6], D[1<<6], dp[1<<6];
string s;

bool Match(){
	int S=0;
	memset(dp, 0, sizeof(dp));
	for (int i=0; i<64; i++) dp[63-i]=D[i], S+=D[i];
	for (int j=0; j<6; j++) for (int i=0; i<64; i++)
		if (i&(1<<j)) dp[i^(1<<j)]+=dp[i];
	
	for (int i=0; i<64; i++){
		int sum=0;
		for (int j=0; j<6; j++) if (i&(1<<j)) sum+=U[j];
		if (sum>S-dp[i]) return 0;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>s>>m;
	n=s.size();
	for (char ch:s) U[ch-'a']++;
	for (int i=1; i<=n; i++) A[i]=63;
	while (m--){
		cin>>x>>s;
		int mask=0;
		for (char ch:s) mask|=(1<<(ch-'a'));
		A[x]=mask;
	}
	for (int i=1; i<=n; i++) D[A[i]]++;
	if (!Match()) kill("Impossible")
	for (int i=1; i<=n; i++){
		D[A[i]]--;
		for (int j=0; j<6; j++) if (A[i]&(1<<j)){
			U[j]--;
			if (Match()){
				cout<<(char)('a'+j);
				break ;
			}
			U[j]++;
		}
	}
	
	return 0;
}