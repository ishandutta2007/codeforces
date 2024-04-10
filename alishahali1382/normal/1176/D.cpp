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
const int MAXN = 2751000, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int sieve[MAXN];
int cnt[MAXN];
int id[MAXN];
vector<int> out;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=2; i*i<MAXN; i++) if (!sieve[i]) for (int j=i; j*i<MAXN; j++) if (!sieve[i*j]) sieve[i*j]=j;
	for (int i=2; i<MAXN; i++) if (!sieve[i]) id[i]=++t;
	cin>>n;
	for (int i=0; i<2*n; i++) cin>>x, cnt[x]++;
	for (int i=MAXN-1; i; i--) while (cnt[i]--){
		if (sieve[i]){
			out.pb(i);
			cnt[sieve[i]]--;
		}
		else{
			out.pb(id[i]);
			cnt[id[i]]--;
		}
	}
	for (int x:out) cout<<x<<' ';
	
	return 0;
}