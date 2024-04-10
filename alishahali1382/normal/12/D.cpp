#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

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

int n, m, k, u, v, x, y, t, a, b, ans;
int B[MAXN], I[MAXN], R[MAXN];
int fen[MAXN];
vector<int> vec[MAXN];
vector<int> comp;

void upd(int pos, int val){
	for (; pos<MAXN; pos+=pos&-pos) fen[pos]=min(fen[pos], val);
}

int get(int pos){
	int res=inf;
	for (; pos; pos-=pos&-pos) res=min(fen[pos], res);
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	// ---------------------------------------------------------------------
	for (int i=1; i<=n; i++){
		cin>>B[i];
		B[i]=-B[i];
		comp.pb(B[i]);
	}
	sort(all(comp));
	comp.resize(unique(all(comp))-comp.begin());
	for (int i=1; i<=n; i++) B[i]=lower_bound(all(comp), B[i])-comp.begin()+1;
	// ---------------------------------------------------------------------
	comp.clear();
	for (int i=1; i<=n; i++){
		cin>>I[i];
		I[i]=-I[i];
		comp.pb(I[i]);
	}
	sort(all(comp));
	comp.resize(unique(all(comp))-comp.begin());
	for (int i=1; i<=n; i++) I[i]=lower_bound(all(comp), I[i])-comp.begin()+1;
	// ---------------------------------------------------------------------
	comp.clear();
	for (int i=1; i<=n; i++){
		cin>>R[i];
		R[i]=-R[i];
		comp.pb(R[i]);
	}
	sort(all(comp));
	comp.resize(unique(all(comp))-comp.begin());
	for (int i=1; i<=n; i++) vec[R[i]=lower_bound(all(comp), R[i])-comp.begin()+1].pb(i);
	// ---------------------------------------------------------------------
	
	memset(fen, 63, sizeof(fen));
	for (int i=1; i<MAXN; i++){
		for (int id:vec[i]) ans+=(get(B[id]-1)<I[id]);
		for (int id:vec[i]) upd(B[id], I[id]);
	}
	cout<<ans<<'\n';
	
	return 0;
}