#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

ll n, m, u, v, x, y, t, a, b, type, p;
ll A[MAXN];
int mark[MAXN], last;
vector<ll> val;
vector<int> ind;

void relax(int i, int time){
	if (ind.empty() || ind.back()<mark[i]) return ;
	int tmp=lower_bound(all(ind), mark[i])-ind.begin();
	mark[i]=ind[tmp];
	A[i]=max(A[i], val[tmp]);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	cin>>m;
	for (int i=1; i<=m; i++){
		cin>>type;
		if (type==2){
			cin>>x;
			while (val.size() && val.back()<x) val.pop_back(), ind.pop_back();
			val.pb(x);
			ind.pb(i);
			continue ;
		}
		cin>>p>>x;
		relax(p, i);
		A[p]=x;
		mark[p]=i;
	}
	for (int i=1; i<=n; i++) relax(i, m+1);
	for (int i=1; i<=n; i++) cout<<A[i]<<" \n"[i==n];
	
	return 0;
}