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
#define debugv(v) {cerr<<#v<<" : ";for (auto abcd:v) cerr<<abcd<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;
#define getbit(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], B[MAXN], mark[MAXN];
map<int, int> mp;

struct SET{
	int sum;
	set<pii> X, Y;
	
	void clear(){
		X.clear();
		Y.clear();
		sum=0;
	}
	void Add(pii p){
		X.insert(p);
		sum+=p.first;
	}
	void Remove(pii p){
		if (X.count(p)){
			X.erase(p);
			sum-=p.first;
		}
		else Y.erase(p);
	}
	void Relax(){
		while (sum>k){
			pii x=*X.rbegin();
			X.erase(x);
			Y.insert(x);
			sum-=x.first;
		}
		while (Y.size() && (Y.begin()->first)+sum<=k){
			pii y=*Y.begin();
			Y.erase(y);
			X.insert(y);
			sum+=y.first;
		}
	}
} st;

int Main(){
	mp.clear();
	st.clear();
	
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>A[i], mp[A[i]]++;
	if (k>=n) kill(0);

	vector<pii> vec;
	for (pii p:mp) if (p.second){
		vec.pb(p);
		st.Add({p.second, p.first});
	}
	st.Relax();
	
	sort(all(vec));
	reverse(all(vec));
	
	ans=max(SZ(st.Y), 1);
	int ted=0;
	for (int mex=0; mex<=n; mex++){
		if (SZ(vec) && vec.back().first==mex){
//			debugp(vec.back())
			pii p=vec.back();
			vec.pop_back();
			st.Remove({p.second, p.first});
			st.Relax();
		}
		else ted++;
		if (ted>k) break ;

		ans=min(ans, SZ(st.Y));
	}
	
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while (T--) Main();
	
	return 0;
}
/*

*/