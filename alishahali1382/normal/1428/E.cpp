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
const int MAXN=300010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN], B[MAXN], C[MAXN];
set<pair<ll, int>> st;

ll get(ll x, ll y){
	if (y>=x) return x;
	ll t=x/y;
	ll a=x-t*y, b=y-a;
	return t*t*b + (t+1)*(t+1)*a;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		ans+=(C[i]=A[i]*A[i]);
		k--;
		B[i]=1;
		st.insert({get(A[i], B[i]+1)-C[i], i});
	}/*
	debug(get(A[1], 1))
	debug(get(A[1], 2))
	
	debug(get(A[1], B[1]+1)-C[1])
	debug(get(A[2], B[2]+1)-C[2])
	*/
	while (k--){
		int i=(st.begin()->second);
		//debug(i)
		st.erase(st.begin());
		ans-=C[i];
		C[i]=get(A[i], ++B[i]);
		ans+=C[i];
		st.insert({get(A[i], B[i]+1)-C[i], i});	
	}
	cout<<ans<<"\n";
	
	return 0;
}