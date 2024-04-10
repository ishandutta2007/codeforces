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
const int MAXN=1000010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], B[MAXN];
int sieve[MAXN], bad[MAXN];
int f[MAXN], cnt[MAXN];
int shit[MAXN];
int fix1[MAXN], fix2[MAXN];
ll F[MAXN];

inline void add(int x, int y){
	if (!shit[x]) shit[x]=y;
	else if (shit[x]!=y){
		cout<<"0\n";
		exit(0);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	for (int i=2; i<MAXN; i++) if (!sieve[i]) for (int j=i; j<MAXN; j+=i) sieve[j]=i;
	for (int i=1; i<MAXN; i++) f[i]=i;
	for (int p=2; p*p<MAXN; p++) for (int i=p*p; i<MAXN; i+=p*p)
		while (f[i]%(p*p)==0) f[i]/=p;
	
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], B[A[i]]=i;
	bad[1]=1;
	for (int i=1; i<=n; i++) if (sieve[i]==i && 2*i>n) bad[i]=1;
	int t=0;
	for (int i=1; i<=n; i++) if (bad[i]){
		if (B[i] && !bad[B[i]]) kill(0)
		if (!B[i]) t++;
	}
	ans=F[t];
//	debug(ans)
	for (int i=1; i<=n; i++) if (!bad[i]) cnt[f[i]]++;
	for (int i=1; i<=n; i++){
		A[i]=f[A[i]];
		if (!bad[A[i]]) cnt[A[i]]--;
	}
	for (int i=1; i<=n; i++) ans=ans*F[cnt[i]]%mod;
//	debug(ans)
	
	for (int i=1; i<=n; i++) if (A[i] && !bad[i]) add(f[i], A[i]);
	for (int p=2; p<=n; p++) if (sieve[p]==p){
		int y=0;
		for (int x=p; x<=n; x+=p) if (shit[x]){
			if (!y) y=x;
			else{
				int g=__gcd(x, y);
				int sx=shit[x], sy=shit[y], sg=__gcd(shit[x], shit[y]);
				shit[x]=shit[y]=0;
				add(x/g, sx/sg);
				add(y/g, sy/sg);
				add(g, sg);
				y=g;
			}
		}
	}
	memset(cnt, 0, sizeof(cnt));
	for (int i=2; i<=n; i++) if (!bad[i] && sieve[i]==i) cnt[n/i]++;
	for (int x=2; x<=n; x++) if (shit[x]){
//		debug2(x, shit[x])
		vector<int> v1, v2;
		for (int tmp=x; tmp>1; tmp/=sieve[tmp]) v1.pb(n/sieve[tmp]), fix1[sieve[tmp]]++;
		for (int tmp=shit[x]; tmp>1; tmp/=sieve[tmp]) v2.pb(n/sieve[tmp]), fix2[sieve[tmp]]++;
		sort(all(v1));
		sort(all(v2));
		if (v1!=v2) kill(0)
		for (int i=0, j=i; i<v1.size(); i=j){
			while (j<v1.size() && v1[i]==v1[j]) j++;
			cnt[v1[i]]-=j-i;
			ans=ans*F[j-i]%mod;
		}
	}
	for (int i=1; i<=n; i++) if (fix1[i]>1 || fix2[i]>1) kill(0)
	for (int i=1; i<=n; i++) ans=ans*F[cnt[i]]%mod;
	cout<<ans<<"\n";
	
	return 0;
}
/*
6
0 0 0 0 0 0
ans: 6

9
0 0 0 0 0 0 0 0 0
ans: 72

10
0 0 0 0 0 0 0 0 0 0
ans: 24



*/