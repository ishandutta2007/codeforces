#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
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
int A[MAXN];

vi join(vi X, vi Y){
	for (int y:Y) X.pb(y);
	return X;
}
int ask(vi vec){
	cout<<"? "<<SZ(vec)<<" ";
	for (int x:vec) cout<<x<<" ";
	cout<<endl;
	string S;
	cin>>S;
	return S=="YES";
}
int found(int x){
	cout<<"! "<<x<<endl;
	string S;
	cin>>S;
	return S==":)";
}

void solve(vi vec){
	if (SZ(vec)==1){
		found(vec[0]);
		return ;
	}
	if (SZ(vec)==2){
		if (!found(vec[0])) found(vec[1]);
		return ;
	}
	if (SZ(vec)==3){
		// FUCK THIS
		int a1=vec[0], a2=vec[1], a3=vec[2];
		if (ask({a1})){
			if (ask({a2})) solve({a1, a2});
			else solve({a1, a3});
			return ;
		}
		if (!ask({a1})){
			solve({a2, a3});
			return ;
		}
		// NO
		// YES
		if (found(a1)) return ;
		if (ask({a2})) found(a2);
		else found(a3);
		return ;
	}
	vi V[4];
	for (int i=0; i<SZ(vec); i++) V[i%4].pb(vec[i]);
	if (!ask(join(V[0], V[1]))){
		swap(V[0], V[2]);
		swap(V[1], V[3]);
	}
	V[1]=join(V[0], V[1]);
	if (ask(V[2])) solve(join(V[1], V[2]));
	else solve(join(V[1], V[3]));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	vi vec(n);
	iota(all(vec), 1);
	solve(vec);
	
	return 0;
}