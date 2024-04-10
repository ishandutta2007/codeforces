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

ll n, m, k, u, v, x, y, t, a, b;
int cnt[20];
int res[20];
ll dp[17][17];
ll C[20][20];

ll f(ll len){
	memset(dp, 0, sizeof(dp));
	dp[0][0]=1;
	for (int i=1; i<=16; i++) for (int j=0; j<=len; j++) for (int tt=0; tt<=min(cnt[i-1], j); tt++) dp[i][j]+=dp[i-1][j-tt]*C[j][tt];
	return dp[16][len];
}

ll solve(int digit){
	//debug(digit)
	memset(res, 0, sizeof(res));
	for (int i=0; i<16; i++) cnt[i]=t;
	for (int i=digit; i>=0; i--){
		for (int x=(i==digit); x<16; x++) if (cnt[x]){
			cnt[x]--;
			ll tmp=f(i);
			if (tmp>k){
				res[i]=x;
				break ;
			}
			k-=tmp;
			cnt[x]++;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=0; i<20; i++){
		C[i][0]=C[i][i]=1;
		for (int j=1; j<i; j++) C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	cin>>k>>t;
	if (k<16) kill("0123456789abcdef"[k])
	k--;
	
	for (int i=0; i<15; i++){
		for (int i=0; i<16; i++) cnt[i]=t;
		cnt[1]--;
		ll tmp=15*f(i);
		cnt[1]++;
		
		if (tmp<=k) k-=tmp;
		else{
			//cerr<<"FUCK "<<i<<endl;
			//debug(k)
			solve(i);
			break ;
		}
	}
	//debug(k)
	
	string ans;
	bool flag=0;
	for (int i=16; ~i; i--) if ((flag|=(res[i]>0))) ans+="0123456789abcdef"[res[i]];
	cout<<ans<<'\n';
	
	return 0;
}
/*
1000 1

ans : 4a3

*/