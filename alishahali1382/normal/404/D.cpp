#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 1000010;

ll n, ans, t, cnt;
ll dp[MAXN][5]; // 0 --> 0     1 --> left bomb   2 --> right bomb    3 --> 2   4 --> *

string s;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>s;
	n=s.size();
	if (n==1){
		if (s=="?") cout<<2<<endl;
		else if (s=="0" || s=="*") cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}
	s='.'+s+'.';
	if (s[1]=='2'){
		cout<<0<<endl;
		return 0;
	}
	if (s[1]=='0' || s[1]=='?') dp[1][0]=1;
	if (s[1]=='1' || s[1]=='?') dp[1][2]=1;
	if (s[1]=='*' || s[1]=='?') dp[1][4]=1;

	for (int i=2; i<n; i++){
		if (s[i]=='0' || s[i]=='?') dp[i][0]=dp[i-1][0]+dp[i-1][1];
		if (s[i]=='1' || s[i]=='?'){
			if (s[i-1]=='*' || s[i-1]=='?') dp[i][1]=dp[i-1][4];
			if (s[i+1]=='*' || s[i+1]=='?') dp[i][2]=dp[i-1][0]+dp[i-1][1];
		}
		if (s[i]=='2' || s[i]=='?' && (s[i+1]=='*' || s[i+1]=='?')) dp[i][3]=dp[i-1][4];
		if ((s[i]=='*' || s[i]=='?') && s[i+1]!='0') dp[i][4]=dp[i-1][2]+dp[i-1][3]+dp[i-1][4];
		for (int j=0; j<5; j++) dp[i][j]%=mod;
	}
	if (s[n]=='2'){
		cout<<0<<endl;
		return 0;
	}
	if ((s[n]=='0' || s[n]=='?') && s[n-1]!='*') dp[n][0]=dp[n-1][0]+dp[n-1][1];
	if ((s[n]=='1' || s[n]=='?') && (s[n-1]=='*' || s[n-1]=='?')) dp[n][1]=dp[n-1][4];
	if (s[n]=='*' || s[n]=='?') dp[n][4]=dp[n-1][2]+dp[n-1][3]+dp[n-1][4];

	ans=dp[n][0]+dp[n][1]+dp[n][4];
	
	cout<<ans%mod<<endl;
	/*
	for (int i=0; i<5; i++){
		for (int j=0; j<=n; j++) cerr<<dp[j][i]<<' ';cerr<<endl;
	}*/
	
	return 0;
}