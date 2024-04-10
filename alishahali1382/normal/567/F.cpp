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
const int MAXN = 36, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll dp[MAXN*2][MAXN*2];
vector<pair<int, string>> vec[MAXN];

bool check(int l, int r, int x, int y){
	for (int shit=0; shit<2; shit++){
		for (auto p:vec[x]) if (l<=p.first && p.first<=r){
			if (p.first==y){
				if (p.second.back()!='=') return 0;
				continue ;
			}
			if (p.second!="<" && p.second!="<=") return 0;
		}
		swap(x, y);
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	while (k--){
		string s;
		cin>>u>>s>>v;
		if (u==v){
			if (s.back()!='=') kill(0)
			continue ;
		} 
		vec[u].pb({v, s});
		if (s[0]=='<') s[0]='>';
		else if (s[0]=='>') s[0]='<';
		vec[v].pb({u, s});
	}
	for (int i=1; i+1<=2*n; i++) dp[i][i+1]=check(i, i+1, i, i+1);
	for (int l=2*n; l; l--) for (int r=l+3; r<=2*n; r+=2){
		if (check(l, r, l, l+1)) dp[l][r]+=dp[l+2][r];
		if (check(l, r, l, r)) dp[l][r]+=dp[l+1][r-1];
		if (check(l, r, r-1, r)) dp[l][r]+=dp[l][r-2];
	}
	cout<<dp[1][2*n]<<'\n';
	/*
	debug(dp[1][6])
	debug2(dp[1][4], check(1, 6, 5, 6))
	debug2(dp[2][5], check(1, 6, 1, 6))
	debug2(dp[3][6], check(1, 6, 1, 2))
	debug(check(1, 6, 1, 2))*/
	
	return 0;
}