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
const int MAXN = 200010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
pii A[MAXN];
vector<int> compX, compY;
vector<int> pos[MAXN];
ll BIT[MAXN];
bool mark[MAXN];

void add(int x, int y){ for (; x<MAXN; x+=x&(-x)) BIT[x]+=y;}
ll get(int id){
	ll res=0;
	for (; id; id-=id&(-id)) res+=BIT[id];
	return res;
}

ll C2(ll x){ return x*(x+1)/2;}

bool cmp(pii i, pii j){
	if (i.second==j.second) return i.first<j.first;
	return i.second<j.second;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>x>>y;
		A[i]={x, y};
		compX.pb(x);
		compY.pb(y);
	}
	sort(all(compX));
	sort(all(compY));
	compX.resize(unique(all(compX))-compX.begin());
	compY.resize(unique(all(compY))-compY.begin());
	for (int i=1; i<=n; i++) A[i]={lower_bound(all(compX), A[i].first)-compX.begin()+1, lower_bound(all(compY), A[i].second)-compY.begin()};
	for (int i=1; i<=n; i++) pos[A[i].second].pb(A[i].first);
	for (int i=0; i<MAXN; i++) sort(all(pos[i]));
	for (int i=n; i>=0; i--) if (pos[i].size()){
		ll tmp=C2(get(pos[i][0]-1))+C2(get(n)-get(pos[i].back()));
		for (int j=1; j<pos[i].size(); j++) tmp+=C2(get(pos[i][j]-1)-get(pos[i][j-1]));
		for (int j:pos[i]) if (!mark[j]){
			mark[j]=1;
			add(j, 1);
		}
		tmp=C2(get(n))-tmp;
		ans+=tmp;
	}
	cout<<ans<<'\n';
	
	return 0;
}