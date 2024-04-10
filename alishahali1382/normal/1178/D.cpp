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
const int MAXN = 2010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
bool sieve[MAXN];
int deg[MAXN];
vector<pii> out;

void add_edge(int u, int v){
	deg[u]++;
	deg[v]++;
	out.pb({u, v});
	m++;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	sieve[0]=sieve[1]=1;
	for (int i=2; i<MAXN; i++) if (!sieve[i]){
		for (int j=i*i; j<MAXN; j+=i) sieve[j]=1;
	}
	cin>>n;
	for (int i=1; i<n; i++) add_edge(i, i+1);
	add_edge(1, n);
	while (sieve[m]){
		int u=0, v=0;
		for (int i=1; i<=n; i++) if (deg[i]==2){
			if (!u) u=i++;
			else{
				v=i;
				break ;
			}
		}
		add_edge(u, v);
	}
	
	cout<<out.size()<<'\n';
	for (pii p:out) cout<<p.first<<' '<<p.second<<'\n';
	
	return 0;
}