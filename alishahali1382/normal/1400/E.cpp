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
const int MAXN=5010;

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN];
int mn[MAXN][MAXN];

int Solve(int tl, int tr, int k){
	if (tl>tr) return 0;
	int res=tr-tl+1;
	int pos=mn[tl][tr]; // with RMQ total complexity is O(n.log)
	res=min(res, A[pos]-k + Solve(tl, pos-1, A[pos]) + Solve(pos+1, tr, A[pos]));
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int r=1; r<=n; r++){
		mn[r][r]=r;
		for (int l=1; l<r; l++){
			if (A[mn[l][r-1]]>A[r]) mn[l][r]=r;
			else mn[l][r]=mn[l][r-1];
		}
	}
	cout<<Solve(1, n, 0)<<"\n";
	
	return 0;
}