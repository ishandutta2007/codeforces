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
const int MAXN = 300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN];
int B[MAXN];
int ans[MAXN];
set<pii> st;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], A[i+n]=A[i+2*n]=A[i];
	int cur=inf;
	for (int i=3*n; i; i--){
		while (st.size() && (*st.begin()).first*2<A[i]){
			int tmp=(*st.begin()).second;
			st.erase({A[tmp], tmp});
			cur=min(cur, tmp);
			//cerr<<i<<' '<<tmp<<"   ";debug2(A[i], A[tmp])
		}
		ans[i]=cur;
		st.insert({A[i], i});
	}
	for (int i=1; i<=n; i++){
		if (ans[i]==inf) cout<<"-1 ";
		else cout<<ans[i]-i<<' ';
	}
	
	return 0;
}