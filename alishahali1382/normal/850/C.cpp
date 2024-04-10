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
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int mark[MAXN];
unordered_map<int, int> G, P;

int get(int x){
	x&=-2;
	if (!x) return 0;
	if (G.count(x)) return G[x];
	for (int t=1; (1<<t)<=x; t++) get((x>>t) | (x&((1<<t)-1)));
	for (int t=1; (1<<t)<=x; t++) mark[get((x>>t) | (x&((1<<t)-1)))]=x;
	int res=0;
	while (mark[res]==x) res++;
	return G[x]=res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>x;
		for (int p=2; p*p<=x; p++) if (x%p==0){
			int t=0;
			while (x%p==0) x/=p, t++;
			P[p]|=(1<<t);
		}
		if (x>1) P[x]|=2;
	}
	for (pii p:P) ans^=get(p.second);
	
	if (!ans) kill("Arpa")
	kill("Mojtaba")
	
	return 0;
}