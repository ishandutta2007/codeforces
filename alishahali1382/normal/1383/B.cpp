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
const int MAXN=100010, LOG=31;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], B[LOG];

int Solve(){
	memset(B, 0, sizeof(B));
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>A[i];
		for (int j=0; j<LOG; j++) if (A[i]&(1<<j)) B[j]++;
	}
	for (int j=LOG-1; ~j; j--) if (B[j]&1){
		if (B[j]%4==3 && n%2==1) kill("LOSE")
		else kill("WIN")
	}
	kill("DRAW")
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);	
	int Test;
	cin>>Test;
	while (Test--) Solve();
	
	return 0;
}
/*

*/