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
const int MAXN = 10000010, LOG=20;

ll n, m, k, u, v, x, y, t, c1, c2, c3, ans;
int sieve[MAXN];
int phi[MAXN];
int ps[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	sieve[1]=phi[1]=1;
	for (int i=2; i<MAXN; i++) if (!sieve[i]) for (int j=i; j<MAXN; j+=i) if (!sieve[j]) sieve[j]=i;
	for (int i=2; i<MAXN; i++){
		int p=sieve[i], tmp=i/p;
		if (tmp%p) phi[i]=(p-1)*phi[tmp];
		else phi[i]=p*phi[tmp];
	}
	cin>>n;
	for (int i=2; i<=n; i++){
		c1+=i-phi[i]-1;
		if (sieve[i]==i && 2*i>n) t++;
	}
	t=n-t-1;
	c3=t*(t-1)/2;
	
	for (int i=2; i<=n; i++) ps[sieve[i]]++;
	for (int i=2; i<=n; i++) ps[i]+=ps[i-1];
	for (int i=2; i<=n; i++) c2+=ps[n/sieve[i]];
	for (int i=2; i<=n; i++) if (1ll*sieve[i]*sieve[i]<=n) c2--;
	c2/=2;
	//debug(c2)
	c2-=c1;
	c3-=c1+c2;
	//debug2(c1, c2)
	//debug(c3)
	cout<<c1+2*c2+3*c3<<'\n';
	
	return 0;
}