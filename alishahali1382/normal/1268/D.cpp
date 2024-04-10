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
const int MAXN = 2010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int deg[MAXN], A[MAXN];
bool G[MAXN][MAXN];

void invert(int v){
	for (int i=1; i<=n; i++) if (v!=i){
		if (G[v][i]){
			deg[v]--;
			deg[i]++;
		}
		else{
			deg[v]++;
			deg[i]--;
		}
		G[v][i]^=1;
		G[i][v]^=1;
	}
}

bool SCC(){
	for (int i=1; i<=n; i++) A[i]=deg[i]-(n-1-deg[i]);
	sort(A+1, A+n+1);
	reverse(A+1, A+n+1);
	int sum=0;
	for (int i=1; i<n; i++){
		sum+=A[i];
		if (sum==i*(n-i)) return 0;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++){
		char ch;
		cin>>ch;
		if (ch=='1') G[i][j]=1, deg[i]++;
	}
	if (SCC()) kill("0 1")
	if (n<=6){
		int mn=n;
		for (int mask=1; mask<(1<<n); mask++){
			for (int i=0; i<n; i++) if (mask&(1<<i)) invert(i+1);
			if (SCC()){
				int tmp=__builtin_popcount(mask);
				if (tmp<mn) mn=tmp, ans=0;
				if (tmp==mn) ans++;
			}
			for (int i=0; i<n; i++) if (mask&(1<<i)) invert(i+1);
		}
		if (mn==n) kill("-1")
		cout<<mn<<' '<<ans*mn<<'\n';
		return 0;
	}
	for (int i=1; i<=n; i++){
		invert(i);
		ans+=SCC();
		invert(i);
	}
	cout<<"1 "<<ans<<'\n';
	
	return 0;
}