#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define all(a) a.begin(),a.end()
#define println printf("\n");
#define readln(x) getline(cin,x);
#define pb push_back
#define endl "\n"
#define INT_INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
#define MOD2 1494318097
#define SEED 131
#define mp make_pair
#define fastio cin.tie(0); cin.sync_with_stdio(0);

#define MAXN 1000005

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef unordered_map<int,int> umii;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef pair<int,pii> triple;
typedef int8_t byte;

mt19937 g1(chrono::steady_clock::now().time_since_epoch().count());

int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g1);}
ll randlong(ll a,ll b){return uniform_int_distribution<long long>(a, b)(g1);}

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

int len,A,B,arr[MAXN];
vector<int> primes;
ll dp[MAXN],res=LLONG_MAX;

inline vector<int> prim(int n){
	vector<int> ret;
	for(int i=2; i<=sqrt(n); i++){
		if(n%i == 0){
			ret.pb(i);
			while(n%i == 0)
				n/=i;
		}
	}
	if(n > 1) ret.pb(n);
	return ret;
}

inline vector<int> combine(vector<int> &a, vector<int> b){
	vector<int> tmp = a;
	for(int check:b) tmp.pb(check);
	sort(all(tmp));
	complete_unique(tmp);
	return tmp;
}

int main(){
	scanf("%d %d %d",&len,&A,&B);
	for(int i=1; i<=len; i++)
		scanf(" %d",&arr[i]);
	for(int i=-1; i<=1; i++){
		if(i == -1) primes = prim(arr[1]+i);
		else primes = combine(primes,prim(arr[1]+i));
		primes = combine(primes,prim(arr[len]+i));
	}
	for(int check:primes){
		memset(dp,0x3f,sizeof dp);
		dp[len+1] = 0;
		for(int i=len; i>=1; i--){
			if(arr[i]%check == 0) dp[i] = dp[i+1];
			else{
				if(arr[i]%check == 1 || arr[i]%check == check-1) dp[i] = dp[i+1]+B;
				else break;
			}
			res = min(res,dp[i]+1LL*(i-1)*A);
		}
		deque<pair<ll,int>> dq;
		for(int i=1; i<=len+1; i++){
			if(dp[i] == LL_INF) continue;
			while(dq.size() && dq.back().first >= dp[i]+1LL*A*i)
				dq.pop_back();
			dq.pb(mp(dp[i]+1LL*A*i,i));
		}
		ll curr = LLONG_MAX;
		dp[0] = 0;
		for(int i=1; i<=len; i++){
			if(arr[i]%check == 0) dp[i] = dp[i-1];
			else{
				if(arr[i]%check == 1 || arr[i]%check == check-1) dp[i] = dp[i-1]+B;
				else dp[i] = LL_INF;
			}
			if(dp[i] == LL_INF) break;
			while(dq.size() && dq.front().second <= i)
				dq.pop_front();
			curr = min(curr,dp[i]-1LL*A*i+dq.front().first-A);
		}
		res = min(res,curr);
	}
	printf("%lld\n",res);
}