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
const int MAXN=200010, M=110;

int n, m, k, u, v, x, y, z, a, b, ans;
int sieve[MAXN], G[MAXN];
bitset<MAXN> mark[M], A;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=2; i<MAXN; i++) if (!sieve[i]) for (int j=i; j<MAXN; j+=i) sieve[j]=i;
	sieve[1]=1;
	cin>>n>>m;
	for (int i=2; i<MAXN; i++) if (i!=m){
		int x=i;
		x/=sieve[x];
		x/=sieve[x];
		if (x==1) A.set(i);
	}
	for (int i=0; i<MAXN; i++){
//		if (i%10000==0) debug(i)
		while (mark[G[i]][i]) G[i]++;
		mark[G[i]]|=(A<<i);
	}
	while (n--){
		cin>>x>>y>>z;
		ans^=G[y-x-1];
		ans^=G[z-y-1];
	}
	cout<<(ans?"Alice":"Bob")<<"\n";
	cout<<(!ans?"Alice":"Bob")<<"\n";
	
	return 0;
}