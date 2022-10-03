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
const int MAXN=1000010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int S[MAXN], A[MAXN], pos[MAXN];
int dp[MAXN], fen[MAXN], val[MAXN];
vector<pii> vec;
vector<int> comp;
vector<int> vec2[MAXN];

void add(int pos, int val){
	for (; pos<MAXN; pos+=pos&-pos) fen[pos]+=val;
}
int get(int pos){
	int res=0;
	for (; pos; pos-=pos&-pos) res+=fen[pos];
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>a;
	while (n--){
		cin>>x>>y;
		if (x<a) continue ;
		vec.pb({y, x});
		comp.pb(x);
		comp.pb(y);
	}
	sort(all(comp));
	sort(all(vec));
	n=SZ(vec);
	for (int i=1; i<=n; i++){
		A[i]=lower_bound(all(comp), vec[i-1].first)-comp.begin()+1;
		S[i]=lower_bound(all(comp), vec[i-1].second)-comp.begin()+1;
	}
	for (int i=1; i<=n; i++){
		pos[i]=upper_bound(A+1, A+i, S[i])-A-1;
		if (pos[i]<i) vec2[pos[i]].pb(i);
		val[i]=i-1-get(A[i]-1);
		add(S[i], +1);
	}
	memset(fen, 0, sizeof(fen));
	for (int i=1; i<=n; i++){
		add(S[i], +1);
		for (int j:vec2[i]) val[j]-=i-get(A[j]-1);
	}
	
	for (int i=1; i<=n; i++){
//		debug2(i, pos[i])
//		for (int j=1; j<=pos[i]; j++) if (A[i]<=S[j]) val[i]--;
//		for (int j=1; j<i; j++) if (A[i]<=S[j]) val[i]++;
		dp[i]=max(dp[i-1], val[i]+dp[pos[i]]+1);
	}
	cout<<dp[n]<<"\n";
	
	return 0;
}