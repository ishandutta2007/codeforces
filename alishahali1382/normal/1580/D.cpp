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
const ll INF=10000000000001000LL;
const int mod=1000000007;
const int MAXN=4010;

int n, k, u, v, x, y, t, a, b;
ll A[MAXN], M;

inline void _upd(ll &x, ll y){ if (x<y) x=y;}

vector<ll> Solve(int tl, int tr){
	if (tr-tl==0) return {0};
	if (tr-tl==1) return {0, M*A[tl]};
	int mid=min_element(A+tl, A+tr)-A;
	auto L=Solve(tl, mid);
	auto R=Solve(mid+1, tr);
	vector<ll> res(tr-tl+1, -INF);
	for (int i=0; i<SZ(L); i++) for (int j=0; j<SZ(R); j++){
		_upd(res[i+j], L[i]+R[j] - 2ll*i*j*A[mid]);
		_upd(res[i+j+1], L[i]+R[j]+A[mid]*M - 2ll*(i*j+i+j)*A[mid]);
		/*
		if (res[i+j]==106){
			debug2(i, j)
			exit(0);
		}
		if (res[i+j+1]==106){
			debug2(i, j)
			exit(0);
		}*/
		
	}
	
//	cerr<<tl<<" "<<tr<<": ";
//	debugv(res)
//	cerr<<"\n";
	
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>M;
	M--;
	for (int i=1; i<=n; i++) cin>>A[i];
	auto res=Solve(1, n+1);
//	ll ans=0;
//	for (int i=1; i<=n; i++) _upd(ans, res[i]);
	cout<<res[M+1]<<"\n";
	
	return 0;
}