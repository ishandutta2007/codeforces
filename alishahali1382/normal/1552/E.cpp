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
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN], dead[MAXN];
pii ans[MAXN];
vector<int> vec[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n*k; i++) cin>>A[i];
	
	int lim=(n-1)/(k-1)+1, curr=2, ted=0;
	for (int i=1; i<=n*k; i++){
		vec[A[i]].pb(i);
		for (int j=1; j<=n; j++) if (!dead[j] && SZ(vec[j])==curr){
			ans[j]={vec[j][curr-2], vec[j][curr-1]};
			dead[j]=1;
			ted++;
			break ;
		}
		if (ted==lim){
			ted=0;
			curr++;
		}
	}
	for (int i=1; i<=n; i++) cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	
	return 0;
}