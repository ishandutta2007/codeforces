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
const int N=410;

int n, m, k, u, v, x, y, t, a, b, ans;
char A[N][N];
int cnt[N][N], ps[N], ted[N];

int Main(){
	cin>>n>>m;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++){
		cin>>A[i][j];
		cnt[i][j]=(A[i][j]-'0')+cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1];
	}
	ans=n*m;
	for (int a=1; a<=n; a++) for (int b=a+4; b<=n; b++){
		int mn=inf;
		for (int i=1; i<=m; i++){
			ted[i]=cnt[b-1][i]-cnt[a][i]-cnt[b-1][i-1]+cnt[a][i-1];
			ps[i]=ps[i-1] + (A[a][i]=='0')+(A[b][i]=='0') + ted[i];
			if (i>=4){
//				debug(mn)
				ans=min(ans, mn + b-a-1-ted[i]/*+(A[a][i]=='1')+(A[b][i]=='0')*/);
			}
			if (i>=3){
				mn=min(mn+ps[i]-ps[i-1], ps[i]-ps[i-2] + b-a-1-ted[i-2]/*+(A[a][i]=='0')+(A[b][i]=='1')*/);
			}
		}
	}
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}