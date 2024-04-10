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

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=1000010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
string S, T;
set<int> st[2];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>S>>T;
	for (int i=0; i<n; i++) if (S[i]!=T[i]) st[S[i]-'0'].insert(i);
	if (st[0].size()!=st[1].size()) kill(-1)
	while (st[0].size()){
		if ((*st[0].begin())>(*st[1].begin())) st[0].swap(st[1]);
		ans++;
		int x=-1;
		while (1){
			auto it0=st[0].lower_bound(x);
			if (it0==st[0].end()) break ;
			int tmp=*it0;
			auto it1=st[1].lower_bound(tmp);
			if (it1==st[1].end()) break ;
			x=*it1;
			st[0].erase(it0);
			st[1].erase(it1);
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}