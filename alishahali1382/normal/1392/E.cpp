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
const int N=30;

ll n, q, k, u, v, x, y, t, a, b;
ll A[N][N];

void Solve(){
	cin>>k;
	cout<<"1 1"<<endl;
	x=y=1;
	for (int ij=2; ij<2*n-1; ij++){
		if (x==n){
			y++;
			cout<<x<<' '<<y<<endl;
			continue ;
		}
		if (y==n){
			x++;
			cout<<x<<' '<<y<<endl;
			continue ;
		}
		if (x&1){
			if (k&A[x+1][y]) x++;
			else y++;
		}
		else{
			if (k&A[x][y+1]) y++;
			else x++;
		}
		cout<<x<<" "<<y<<endl;
	}
	cout<<n<<" "<<n<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	x=1;
	for (int i=2; i<=n; i+=2) for (int j=1; j<=n; j++) A[i][j]=(1ll<<(i+j));
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++) cout<<A[i][j]<<" ";
		cout<<endl;
	}
	cin>>q;
	while (q--) Solve();
	
	return 0;
}