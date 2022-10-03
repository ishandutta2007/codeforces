#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
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

int n, m, k, u, v, x, y, t, l, r, ans;
int A[MAXN];
bool mark[MAXN];
set<int> st;
vector<pii> vec;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	while (m--){
		cin>>t>>l>>r;
		if (t) for (int x=l+1; x<=r; x++) mark[x]=1;
		else vec.pb({l, r});
	}
	for (pii p:vec){
		bool f=0;
		for (int i=p.first+1; i<=p.second; i++) if (!mark[i]) f=1;
		if (!f) kill("NO")
	}
	A[n+1]=1;
	for (int i=n; i; i--) A[i]=A[i+1]+1-mark[i+1];
	
	cout<<"YES\n";
	for (int i=1; i<=n; i++) cout<<A[i]<<' ';cout<<'\n';
	
	return 0;
}