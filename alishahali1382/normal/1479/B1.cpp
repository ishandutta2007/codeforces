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
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], last[MAXN];
int seg[MAXN<<1];

void Set(int i, int val){
	for (seg[i+=n+1]=val; i>1; i>>=1) seg[i>>1]=max(seg[i], seg[i^1]);
}
int Get(int l, int r){
	int res=-inf;
	for (l+=n+1, r+=n+1; l<r; l>>=1, r>>=1){
		if (l&1) res=max(res, seg[l++]);
		if (r&1) res=max(res, seg[--r]);
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	memset(seg, -31, sizeof(seg));
	Set(0, 1);
	int lazy=0;
	for (int i=2; i<=n; i++){
		int val=max(Get(0, A[i]), Get(A[i]+1, n+1))+lazy+1;
		val=max(val, Get(A[i], A[i]+1)+lazy);
//		val=max(val, Get(0, 1)+lazy);
		lazy+=(A[i]!=A[i-1]);
		Set(A[i-1], val-lazy);
//		cerr<<i<<": ";for (int j=0; j<=n; j++) cerr<<Get(j, j+1)+lazy<<" \n"[j==n];
	}
	cout<<Get(0, n+1)+lazy<<"\n";
	
	return 0;
}
/*
3
1 1 2

5
1 1 2 1 1

*/