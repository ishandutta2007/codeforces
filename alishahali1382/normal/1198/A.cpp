#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
const int MAXN = 400010, LOG=20;

ll n, I, k, u, v, x, y, t, a, b, ans;
ll A[MAXN];
ll B[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>I;
	for (int i=1; i<=n; i++) cin>>A[i];
	sort(A+1, A+n+1);
	B[1]=1;
	for (int i=2; i<=n; i++) B[i]=B[i-1]+(A[i]!=A[i-1]);
	I*=8;
	I/=n;
	I=min(32ll, I);
	I=1ll<<I;
	ans=n;
	for (int i=1; i<=n; i++){
		int ind=lower_bound(B+1, B+n+1, B[i]+I)-B;
		//debug2(i, ind)
		//debug2(i, i+n-ind)
		ans=min(ans, i+n-ind);
	}
	kill(ans)
	
	return 0;
}