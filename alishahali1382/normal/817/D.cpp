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
const int MAXN = 1000010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN];
ll L1[MAXN], R1[MAXN];
ll L2[MAXN], R2[MAXN];
stack<int> stk;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], A[i]++;
	
	stk.push(0);
	for (int i=1; i<=n; i++){
		while (A[stk.top()]>A[i]) stk.pop();
		L1[i]=stk.top();
		stk.push(i);
	}
	while (stk.size()) stk.pop();
	
	A[0]=inf;
	stk.push(0);
	for (int i=1; i<=n; i++){
		while (A[stk.top()]<A[i]) stk.pop();
		L2[i]=stk.top();
		stk.push(i);
	}
	while (stk.size()) stk.pop();
	
	
	A[n+1]=0;
	stk.push(n+1);
	for (int i=n; i; i--){
		while (A[stk.top()]>=A[i]) stk.pop();
		R1[i]=stk.top();
		stk.push(i);
	}
	while (stk.size()) stk.pop();
	
	A[n+1]=inf;
	stk.push(n+1);
	for (int i=n; i; i--){
		while (A[stk.top()]<=A[i]) stk.pop();
		R2[i]=stk.top();
		stk.push(i);
	}
	while (stk.size()) stk.pop();
	
	for (int i=1; i<=n; i++){
		ans+=(i-L2[i])*(R2[i]-i)*A[i];
		ans-=(i-L1[i])*(R1[i]-i)*A[i];
	}
	cout<<ans<<'\n';
	
	return 0;
}