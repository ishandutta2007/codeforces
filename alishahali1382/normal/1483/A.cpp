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
int A[MAXN], B[MAXN];
vector<int> vec[MAXN];

int Solve(){
	cin>>n>>m;
	for (int i=1; i<=n; i++) A[i]=0;
	for (int i=1; i<=m; i++){
		cin>>x;
		vec[i].resize(x);
		for (int j=0; j<x; j++) cin>>vec[i][j];
		A[vec[i].back()]++;
	}
	int bad=0;
	for (int i=1; i<=n; i++) if (A[i]>(m+1)/2) bad=i;
	if (bad){
		int ted=A[bad]-(m+1)/2;
		for (int i=1; i<=m && ted; i++) if (vec[i].size()>1 && vec[i].back()==bad){
			vec[i].pop_back();
			ted--;
		}
		if (ted) kill("NO")
	}
	cout<<"YES\n";
	for (int i=1; i<=m; i++) cout<<vec[i].back()<<" \n"[i==m];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;	
	cin>>T;
	while (T--) Solve();
	
	return 0;
}