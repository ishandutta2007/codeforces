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
int A[MAXN], L[MAXN], R[MAXN];
vector<pii> vec;

bool check(int l1, int r1, int l2, int r2){
	return max(l1, l2)>min(r1, r2);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=2; i<=n; i++) if (A[i-1]<A[i]) L[i]=L[i-1]+1;
	for (int i=n-1; i; i--) if (A[i]>A[i+1]) R[i]=R[i+1]+1;
	int mx=0, X=-1;
	for (int i=2; i<n; i++) if (L[i]==R[i] && L[i]>mx){
		mx=L[i];
		X=i;
	}
	if (X==-1 || L[X]%2) kill(0)
	for (int i=1; i<=n; i++) if (i!=X){
		if (max(L[i], R[i])>L[X]) kill(0)
		if (R[i]==L[X]) kill(0)
		if (L[i]==L[X]) kill(0)
	}
	
	cout<<"1\n";
	
	return 0;
}