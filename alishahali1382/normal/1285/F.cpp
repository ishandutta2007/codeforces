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
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
ll ans;
bool A[MAXN];
short mob[MAXN];
int ted[MAXN];
stack<int> stk;
vector<int> D[MAXN];

inline void add(int x, int w){
	for (int d:D[x]) ted[d]+=w;
}
inline int get(int x){
	int res=0;
	for (int d:D[x]) res+=ted[d]*mob[d];
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	mob[1]=1;
	for (int i=1; i<MAXN; i++) for (int j=i+i; j<MAXN; j+=i) mob[j]-=mob[i];
	for (int i=1; i<MAXN; i++) for (int j=i; j<MAXN; j+=i) D[j].pb(i);
	cin>>n;
	while (n--) cin>>x, A[x]=1, ans=max(ans, (ll)x);
	for (int i=1; i<MAXN; i++) for (int j=i+i; j<MAXN && !A[i]; j+=i) A[i]|=A[j];
	for (int i=MAXN-1; i; i--) if (A[i]){
		while (stk.size()){
			int x=stk.top();
			add(x, -1);
			if (!get(i)){
				add(x, +1);
				break ;
			}
			stk.pop();
		}
		if (get(i)) ans=max(ans, 1ll*i*stk.top());
		stk.push(i);
		add(i, +1);
	}
		
	cout<<ans<<'\n';
	
	return 0;
}