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
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
vector<pii> vec;

void found(int a, int b){
	cout<<"YES\n";
	cout<<a<<' '<<b<<' '<<n/a/b<<'\n';
}

void solve(){
	vec.clear();
	cin>>n;
	int m=n;
	for (int i=2; i*i<=m; i++) if (m%i==0){
		int t=0;
		while (m%i==0) m/=i, t++;
		vec.pb({i, t});
	}
	if (m>1) vec.pb({m, 1});
	if (vec.size()>2){
		found(vec[0].first, vec[1].first);
		return ;
	}
	if (vec.size()==1){
		if (vec[0].second>=6) found(vec[0].first, vec[0].first*vec[0].first);
		else cout<<"NO\n";
		return ;
	}
	if (vec[0].second<vec[1].second) swap(vec[0], vec[1]);
	int p=vec[0].first, a=vec[0].second;
	int q=vec[1].first, b=vec[1].second;
	if (b>=2 || a>2){
		found(p, q);
		return ;
	}
	cout<<"NO\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) solve();
	
	return 0;
}