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
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int N=1010;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[N][N];

void Solve(int l, int r, int val){
	if (r<=l) return ;
	for (int i=l; i<=r; i++) for (int j=i+1; j<=r; j++) A[i][j]=val;
	vector<int> shit(k, (r-l+1)/k);
	for (int i=0; i<((r-l+1)%k); i++) shit[i]++;
	for (int i=0; i<k; i++){
		Solve(l, l+shit[i]-1, val-1);
		l+=shit[i];
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	int shit=1;
	while (shit<n){
		shit*=k;
		ans++;
	}
	Solve(1, n, ans);
	cout<<ans<<"\n";
	for (int i=1; i<=n; i++) for (int j=i+1; j<=n; j++) cout<<A[i][j]<<" ";
	cout<<"\n";
	
	return 0;
}