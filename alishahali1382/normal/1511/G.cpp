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

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=270010, LOG=17;

int n, m, k, u, v, x, y, t, l, r;
int A[MAXN], ans[2*MAXN];
vector<pii> Q[MAXN];

struct Fenwick{
	bool fen[MAXN];
	void upd(int pos){
		for (pos++; pos<MAXN; pos+=pos&-pos) fen[pos]^=1;
	}
	int get(int pos){
		bool res=0;
		for (pos++; pos; pos-=pos&-pos) res^=fen[pos];
		return res;
	}
} fen[LOG];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>m>>n;
	while (m--){
		cin>>x;
		A[x]^=1;
	}
	cin>>m;
	for (int i=0; i<m; i++){
		cin>>l>>r;
		Q[l-1].pb({l, 2*i});
		Q[r].pb({l, 2*i+1});
	}
	int ted=0, val=0;
	for (int i=1; i<=n; i++){
		if (A[i]){
			for (int j=0; j<LOG; j++) fen[j].upd(i&((2<<j)-1));
			ted++;
			val^=i;
		}
		for (pii p:Q[i]){
			int res=val, x=p.first, id=p.second;
			if (ted&1) res^=x;
			for (int j=1; j<=LOG; j++) if (fen[j-1].get((x&((1<<j)-1))-1)) res^=(1<<j);
			ans[id]=res;
		}
	}
	
	for (int i=0; i<m; i++) cout<<(ans[2*i]^ans[2*i+1]?'A':'B');
	cout<<"\n";
	
	return 0;
}