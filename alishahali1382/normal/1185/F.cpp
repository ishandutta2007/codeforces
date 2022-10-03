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
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, c, ans, ans1=1, ans2=2, cost=2*inf;
int val[1<<9];
vector<pii> vec[1<<9];

void update(int i, int j, int emt, int C){
	if (ans>emt) return ;
	if (ans==emt && C<cost){
		cost=C;
		ans1=i;
		ans2=j;
		return ;
	}
	if (ans<emt){
		cost=C;
		ans=emt;
		ans1=i;
		ans2=j;
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	while (n--){
		int mask=0;
		cin>>k;
		while (k--) cin>>x, mask|=(1<<(x-1));
		val[mask]++;
	}
	for (int mask=(1<<9)-1; mask; mask--) for (int M=(mask-1)&mask; M; M=(M-1)&mask) val[mask]+=val[M];
	for (int i=1; i<=m; i++){
		int mask=0;
		cin>>c>>k;
		while (k--) cin>>x, mask|=(1<<(x-1));
		vec[mask].pb({c, i});
	}
	for (int i=1; i<(1<<9); i++) sort(all(vec[i]));
	for (int i=1; i<(1<<9); i++) if (vec[i].size()) for (int j=i+1; j<(1<<9); j++) if (vec[j].size()) update(vec[i][0].second, vec[j][0].second, val[i|j], vec[i][0].first+vec[j][0].first);
	for (int i=1; i<(1<<9); i++) if (vec[i].size()>=2) update(vec[i][0].second, vec[i][1].second, val[i], vec[i][0].first+vec[i][1].first);
	
	cout<<ans1<<' '<<ans2<<'\n';
	
	return 0;
}