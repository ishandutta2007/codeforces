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
int mark[MAXN], C[MAXN];
vector<int> vec[MAXN];

int Solve(){
	cin>>n>>x>>y;
	vector<int> X, Y;
	for (int i=1; i<=n; i++){
		cin>>C[i];
		mark[i]=0;
		vec[i].clear();
	}
	sort(C+1, C+x+1);
	sort(C+x+1, C+n+1);
	ans=0;
	for (int i=1; i<=x; i++) vec[C[i]].pb(i);
	for (int i=x+1; i<=n; i++) if (vec[C[i]].size()){
		mark[vec[C[i]].back()]=mark[i]=1;
		vec[C[i]].pop_back();
	}
	for (int i=1; i<=x; i++) if (!mark[i]) X.pb(C[i]);
	for (int i=x+1; i<=n; i++) if (!mark[i]) Y.pb(C[i]);
	if (X.size()<Y.size()) swap(X, Y);
	int ted=0, tmp=1, last;
	for (int x:X){
		if (tmp) tmp=0;
		else if (last==x){
			ted++;
			tmp=1;
		}
		last=x;
	}
	ans+=Y.size();
	int shit=X.size()-Y.size();
	ans+=shit-min(shit/2, ted);
	kill(ans)
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T=1;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}