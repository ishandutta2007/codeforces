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
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 400010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
pll P[MAXN];
ll A[MAXN], T[MAXN];
multiset<pll> st;

bool cmp(pll i, pll j){
	if (i.first==j.first) return i.second>j.second;
	return i.first<j.first;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>P[i].first;
	for (int i=1; i<=n; i++) cin>>P[i].second;
	sort(P+1, P+n+1, cmp);
	for (int i=1; i<=n; i++) A[i]=P[i].first, T[i]=P[i].second;
	
	for (int i=1; i<=n; i++){
		if (A[i]==A[i-1]){
			st.insert({T[i], A[i]});
			continue ;
		}
		int j=A[i-1];
		while (st.size()>0 && j<A[i]){
			pll p=*st.rbegin();
			ans+=p.first*(1ll*j-p.second);
			st.erase(st.find(p));
			j++;
		}
		st.insert({T[i], A[i]});
	}
	int j=A[n];
	while (st.size()>0){
		pll p=*st.rbegin();
		ans+=p.first*(1ll*j-p.second);
			st.erase(st.find(p));
		j++;
	}
	
	cout<<ans<<'\n';
	
	return 0;
}