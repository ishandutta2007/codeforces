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

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];

bool check(int d){
	if (abs(x-y)>d) return 0;
	set<int> st;
	st.insert(x);
	st.insert(y);
	for (int i=1; i<=n; i++){
		int z=A[i];
		while (st.size() && abs((*st.begin())-z)>d) st.erase(st.begin());
		while (st.size() && abs((*st.rbegin())-z)>d) st.erase(*st.rbegin());
		if (st.empty()) return 0;
		st.insert(z);
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>x>>y;
	for (int i=1; i<=n; i++) cin>>A[i];
	int dwn=-1, up=inf;
	while (up-dwn>1){
		int mid=(dwn+up)>>1;
		if (check(mid)) up=mid;
		else dwn=mid;
	}
	cout<<up<<'\n';
	
	return 0;
}