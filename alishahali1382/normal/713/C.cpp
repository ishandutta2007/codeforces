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
const int MAXN=300010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans, opt;
ll A[MAXN];
multiset<ll> st;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	st.insert(opt=-inf);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		A[i]-=i;
		if (opt<=A[i]) st.insert(opt=A[i]);
		else{
			ans+=abs(A[i]-opt);
			st.insert(A[i]);
			st.insert(A[i]);
			st.erase(st.find(*st.rbegin()));
			opt=*st.rbegin();
		}
//		debug2(i, opt)
	}
	cout<<ans<<"\n";
	
	return 0;
}