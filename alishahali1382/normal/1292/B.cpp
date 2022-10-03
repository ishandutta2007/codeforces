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
const ll INF=20000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

ll n=1, x0, y0, ax, ay, bx, by, xs, ys, t, ans;
ll A[MAXN][2];

ll calc(ll x, ll y, ll xx, ll yy){
	return abs(x-xs)+abs(y-ys)+abs(x-xx)+abs(y-yy);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>x0>>y0>>ax>>ay>>bx>>by>>xs>>ys>>t;
	
	A[0][0]=x0;
	A[0][1]=y0;
	while (max(A[n-1][0], A[n-1][1])<INF){
		A[n][0]=ax*A[n-1][0]+bx;
		A[n][1]=ay*A[n-1][1]+by;
		n++;
	}
	
	for (int i=0; i<n; i++) for (int j=0; j<n; j++)
		if (calc(A[i][0], A[i][1], A[j][0], A[j][1])<=t)
			ans=max(ans, abs(i-j)+1ll);
	
	cout<<ans<<'\n';
	
	return 0;
}