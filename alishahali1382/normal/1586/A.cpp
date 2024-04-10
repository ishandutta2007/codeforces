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
const int MAXN=20010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], good[MAXN];
bitset<MAXN> dp;

int Main(){
	cin>>n;
	int sum=0;
	for (int i=1; i<=n; i++) cin>>A[i], sum+=A[i];
	if (good[sum]){
		cout<<n<<"\n";
		for (int i=1; i<=n; i++) cout<<i<<" \n"[i==n];
		return 0;
	}
	assert(sum%2==1);
	for (int i=1; i<=n; i++) if (good[sum-A[i]]){
		cout<<n-1<<"\n";
		for (int j=1; j<=n; j++) if (j!=i) cout<<j<<" ";
		cout<<"\n";
		return 0;
	}
	cout<<1/0;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=2; i<MAXN; i++) for (int j=2*i; j<MAXN; j+=i) good[j]=1;	
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}