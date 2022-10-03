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
#define get(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=1000010, K=20;

int n, m, k, u, v, x, y, L, R, ans=-1;
int A[MAXN], B[MAXN];
int S[MAXN], T[MAXN];
int mn[1<<K], mx[1<<K], to[K];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k;
	char ch;
	for (int i=0; i<k; i++) cin>>ch, S[0]|=((ch-'0')<<i);
	for (int i=0; i<k; i++) cin>>ch, T[0]|=((ch-'0')<<i), to[i]=i;
	for (int i=1; i<=n; i++){
		cin>>A[i]>>B[i];
		swap(to[--A[i]], to[--B[i]]);
		for (int j=0; j<k; j++){
			S[i]|=(get(S[0], j)<<to[j]);
			T[i]|=(get(T[0], j)<<to[j]);
		}
	}
	memset(mn, 31, sizeof(mn));
	memset(mx, -31, sizeof(mn));
	for (int i=0; i<=n; i++){
		mn[S[i]]=min(mn[S[i]], i);
		mx[T[i]]=max(mx[T[i]], i);
	}
	for (int j=0; j<k; j++) for (int i=0; i<(1<<k); i++) if (get(i, j)){
		mn[i^(1<<j)]=min(mn[i^(1<<j)], mn[i]);
		mx[i^(1<<j)]=max(mx[i^(1<<j)], mx[i]);
	}
	for (int i=0; i<(1<<k); i++) if (mx[i]-mn[i]>=m && __builtin_popcount(i)>ans){
		ans=__builtin_popcount(i);
		L=mn[i];
		R=mx[i];
	}
	ans*=2;
	for (int i=0; i<k; i++) ans-=get(S[0], i)+get(T[0], i);
	cout<<ans+k<<"\n";
	cout<<L+1<<" "<<R<<"\n";
	
	return 0;
}