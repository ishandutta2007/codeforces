#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ld, ld> pll;
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

ll n, m, k, u, v, t, a, b, ans, all;
ld x, y;
map<ll, vector<pll>> mp;
map<ld, ll> cnt, online;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	while (n--){
		cin>>t>>x>>y;
		ll tmp=x*x+y*y;
		if (t==1){
			all++;
			online[x/y]++;
			mp[tmp].pb({x, y});
			for (pll p:mp[tmp]) cnt[(x+p.first)/(y+p.second)]++;
			continue ;
		}
		if (t==2){
			all--;
			online[x/y]--;
			for (pll p:mp[tmp]) cnt[(x+p.first)/(y+p.second)]--;
			for (int i=0; i<mp[tmp].size()-1; i++) if (mp[tmp][i]==make_pair(x, y)) swap(mp[tmp][i], mp[tmp][i+1]);
			mp[tmp].pop_back();
			continue ;
		}
		ans=2*cnt[x/y]-online[x/y];
		cout<<all-ans<<'\n';
	}
	
	return 0;
}