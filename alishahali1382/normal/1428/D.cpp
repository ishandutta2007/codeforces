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

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
vector<pii> out;
vector<int> vec1, vec23;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=n; i; i--) if (A[i]){
		debug(i)
		if (A[i]==1){
			vec1.pb(i);
			continue ;
		}
		if (A[i]==2){
			if (vec1.empty()) kill(-1)
			int j=vec1.back();
			vec1.pop_back();
			out.pb({n+1-i, i});
			out.pb({n+1-i, j});
		}
		else{
			int j;
			if (vec23.empty()){
				if (vec1.empty()) kill(-1)
				j=vec1.back();
				vec1.pop_back();
				out.pb({n+1-i, i});
				out.pb({n+1-i, j});
				out.pb({n+1-j, j});
				
			}
			else{
				j=vec23.back();
				vec23.pop_back();	
				out.pb({n+1-i, i});
				out.pb({n+1-i, j});
			}
		}
		vec23.pb(i);
	}
	for (int i:vec1) out.pb({n+1-i, i});
	cout<<out.size()<<"\n";
	for (pii p:out) cout<<n+1-p.first<<" "<<p.second<<"\n";
	
	return 0;
}
/*
4
2 3 1 1

*/