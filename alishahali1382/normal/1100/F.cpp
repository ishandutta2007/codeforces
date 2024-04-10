#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")

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
const int MAXN = 500010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, l, r;
int A[MAXN];
int ans[MAXN];
piii query[MAXN];
vector<int> pref[MAXN], suff[MAXN];

inline int hb(int x){ return 1<<(31-__builtin_clz(x));}

inline void add(vector<int> &vec, int x){
	//debugv(vec)
	for (int a:vec) if (x&hb(a)) x^=a;
	//debug(x)
	if (!x) return ;
	for (int &a:vec) if (a&hb(x)) a^=x;
	vec.pb(x);
}

vector<int> combine(vector<int> v1, vector<int> v2){
	if (v1.size()>=LOG) return v1;
	if (v2.size()>=LOG) return v2;
	vector<int> res=v1;
	for (int x:v2){
		add(res, x);
		if (res.size()>=LOG) break ;
	}
	return res;
}

int calc(vector<int> vec){
	//debug("calced")
	int res=0;
	for (int x:vec) res=max(res, res^x);
	return res;
}

void conquer(int tl, int tr){
	int ql=lower_bound(query+1, query+m+1, make_pair(make_pair(tl, 0), 0))-query;
	int qr=lower_bound(query+1, query+m+1, make_pair(make_pair(tr, 0), 0))-query;
	//cerr<<tl<<' '<<tr<<' '<<ql<<' '<<qr<<endl;
	int mid=(tl+tr)>>1;
	pref[mid].clear();
	for (int i=mid-1; i>=tl; i--){
		pref[i]=pref[i+1];
		add(pref[i], A[i]);
	}
	suff[mid-1].clear();
	for (int i=mid; i<tr; i++){
		suff[i]=suff[i-1];
		add(suff[i], A[i]);
	}
	for (int i=ql; i<qr; i++) if (query[i].first.first<=mid && query[i].first.second<tr && mid-1<=query[i].first.second) ans[query[i].second]=calc(combine(pref[query[i].first.first], suff[query[i].first.second]));
}

void divide(int tl, int tr){
	//cerr<<"divide "<<tl<<' '<<tr<<endl;
	if (tr-tl>1){
		int mid=(tl+tr)>>1;
		divide(tl, mid);
		divide(mid, tr);
	}
	conquer(tl, tr);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	
	cin>>m;
	for (int i=1; i<=m; i++){
		cin>>query[i].first.first>>query[i].first.second;
		query[i].second=i;
	}
	sort(query+1, query+m+1);
	divide(1, n+1);
	
	for (int i=1; i<=m; i++) cout<<ans[i]<<'\n';
	
	return 0;
}
/*
5
12 14 23 13 7
1
1 1
*/