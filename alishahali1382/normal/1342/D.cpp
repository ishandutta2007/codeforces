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
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=200010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans=1;
int C[MAXN], cnt[MAXN];
vector<int> out[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>x, cnt[x]++;
	for (int i=1; i<=k; i++) cin>>C[i];
	int pos=1;
	for (int i=k; i; i--){
		if (i!=k && C[i]!=C[i+1]) pos=1;
		while (cnt[i]--){
			while (out[pos].size()>=C[i]) ans=max(ans, ++pos);
			out[pos].pb(i);
		}
	}
	cout<<ans<<'\n';
	for (int i=1; i<=ans; i++){
		cout<<out[i].size()<<' ';
		for (int j:out[i]) cout<<j<<' ';
		cout<<'\n';
	}
	
	
	return 0;
}