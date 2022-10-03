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
#define getbit(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010;

ll n, m, k, u, v, x, y, t, a, b, ans=INF;
ll A[MAXN];

ll Solve(int mid){
	ll res=0;
	ll last=0;
	for (int i=mid+1; i<=n; i++){
		ll val=last/A[i], tmp=val*A[i];
		while (tmp<=last) tmp+=A[i], val++;
		while (last<tmp-A[i]) tmp-=A[i], val--;
		res+=val;
		last=tmp;
	}
	last=0;
	for (int i=mid-1; i; i--){
		ll val=last/A[i], tmp=val*A[i];
		while (tmp<=last) tmp+=A[i], val++;
		while (last<tmp-A[i]) tmp-=A[i], val--;
		res+=val;
		last=tmp;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=n; i++) ans=min(ans, Solve(i));
	cout<<ans<<"\n";
	
	return 0;
}