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
const int mod=1000000007;
const int MAXN=2010, LOG=20;
string num[]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int dig[]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int n, m, k, u, v, x, y, t, a, b, ans;
bool dp[MAXN][MAXN][11];
int cnt[MAXN];
string S[MAXN];

bool ok(string s, string t){ // s --> t
	for (int i=0; i<7; i++) if (s[i]=='1' && t[i]=='0') return 0;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++){
		cin>>S[i];
		for (char ch:S[i]) cnt[i]+=ch-'0';
	}
	
	dp[n+1][0][10]=1;
	for (int i=n; i; i--) for (int j=0; j<=k; j++){
		for (int x=0; x<10; x++)
			if (ok(S[i], num[x]) && dig[x]-cnt[i]<=j)
				dp[i][j][10]|=(dp[i][j][x]=dp[i+1][j-(dig[x]-cnt[i])][10]);
	}
	
	if (!dp[1][k][10]) kill(-1)
	for (int i=1; i<=n; i++){
		for (int j=9; ~j; j--) if (dp[i][k][j]){
			cout<<j;
			k-=dig[j]-cnt[i];
			break ;
		}
	}
	cout<<'\n';
	
	
	return 0;
}