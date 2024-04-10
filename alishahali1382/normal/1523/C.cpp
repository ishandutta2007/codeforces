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
const int N=1010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[N], mark[N], par[N];
vector<int> vec[N];

int Solve(){
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], mark[i]=0;
	vec[1]={1};
	for (int i=2; i<=n; i++){
		if (A[i]==1) vec[i]=vec[i-1], par[i]=i-1;
		else{
			int x=i-1;
			while (A[x]!=A[i]-1) x=par[x];
			
			/*
			for (int j=1; j<i; j++){
				if (A[j]==A[i]-1 && !mark[j]){
					x=j;
					break ;
				}
			}*/
			assert(x);
			mark[x]=1;
			par[i]=par[x];
//			debug2(i, x)
			vec[i]=vec[x];
			vec[i].pop_back();
		}
		vec[i].pb(A[i]);
	}
	for (int i=1; i<=n; i++){
		int sz=vec[i].size();
		for (int j=0; j<sz; j++){
			cout<<vec[i][j];
			if (j==sz-1) cout<<"\n";
			else cout<<".";
		}
	}
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