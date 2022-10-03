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
const int MAXN = 110, LOG=20;

int n, m, k, u, v, x, y, t, a, b, N;
pii A[MAXN];
int pos[MAXN], le[MAXN], ri[MAXN];
int dp[MAXN][3*MAXN];
int ps[MAXN*3];
vector<int> compress;
vector<pii> vec;

int Find(int x){
	return lower_bound(all(compress), x)-compress.begin();
}

int Len(int l, int r){
	return compress[r]-compress[l];
}

void Add(int l, int r, int lim){
	l=min(l, lim);
	r=min(r, lim);
	/*
	vec.pb({l, +1});
	vec.pb({r, -1});
	*/
	ps[l]++;
	ps[r]--;
}

int Calc(){
	//sort(all(vec));
	int res=0;
	for (int i=0; i<N; i++) ps[i]+=ps[i-1];
	for (int i=0; i<N-1; i++) if (ps[i]) res+=Len(i, i+1);
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>x>>y;
		compress.pb(x);
		compress.pb(x-y);
		compress.pb(x+y);
		A[i]={x, y};
	}
	sort(all(compress));
	compress.resize(unique(all(compress))-compress.begin());
	N=compress.size();
	
	sort(A+1, A+n+1);
	for (int i=1; i<=n; i++){
		le[i]=Find(A[i].first-A[i].second);
		pos[i]=Find(A[i].first);
		ri[i]=Find(A[i].first+A[i].second);
	}
	
	for (int i=1; i<=n; i++) for (int j=0; j<N; j++){
		memset(ps, 0, sizeof(ps));
		for (int ind=1; ind<=i; ind++) Add(le[ind], pos[ind], j);
		dp[i][j]=Calc();
		
		for (int ii=i; ii; ii--){
			int jj=min(j, pos[ii]);
			memset(ps, 0, sizeof(ps));
			Add(pos[ii], ri[ii], j);
			for (int ind=ii+1; ind<=i; ind++){
				Add(le[ind], pos[ind], j);
				jj=min(jj, le[ind]);
			}
			dp[i][j]=max(dp[i][j], dp[ii-1][jj] + Calc());
		}
	}
	
	cout<<dp[n][compress.size()-1]<<'\n';
	
	return 0;
}
/*
3
1 2
3 3
4 3

*/