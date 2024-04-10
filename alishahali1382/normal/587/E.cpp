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

struct FENWICK{
	int BIT[MAXN];
	void upd(int id, int x){
		for (; id<MAXN; id+=id&(-id)) BIT[id]^=x;
	}
	void update(int l, int r, int x){
		upd(l, x);
		upd(r+1, x);
	}
	int get(int id){
		int res=0;
		for (; id; id-=id&(-id)) res^=BIT[id];
		return res;
	}
} fen;

int n, m, k, u, v, x, y, t, a, b, l, r;
int A[MAXN];
vector<int> seg[MAXN<<2];

void add(vector<int> &vec, int x){
	for (int a:vec) if (a&(-a)&x) x^=a;
	if (!x) return ;
	for (int &a:vec) if (x&(-x)&a) a^=x;
	vec.pb(x);
}

vector<int> combine(vector<int> v1, vector<int> v2){
	for (int x:v2) add(v1, x);
	return v1;
}

void build(int id, int tl, int tr){
	if (tl==tr){
		if (A[tl]) seg[id].pb(A[tl]);
		return ;
	}
	int mid=(tl+tr)>>1;
	build(id<<1, tl, mid);
	build(id<<1 | 1, mid+1, tr);
	seg[id]=combine(seg[id<<1], seg[id<<1 | 1]);
}

void update(int id, int tl, int tr, int x, int y){
	if (x<tl || tr<x) return ;
	if (tl==tr){
		if (y) seg[id]={y};
		else seg[id].clear();
		return ;
	}
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, x, y);
	update(id<<1 | 1, mid+1, tr, x, y);
	seg[id]=combine(seg[id<<1], seg[id<<1 | 1]);	
}

vector<int> get(int id, int tl, int tr, int l, int r){
	if (r<tl || tr<l) return {};
	if (l<=tl && tr<=r) return seg[id];
	int mid=(tl+tr)>>1;
	return combine(get(id<<1, tl, mid, l, r), get(id<<1 | 1, mid+1, tr, l, r));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i], fen.update(i, i, A[i]);
	for (int i=n; i; i--) A[i]^=A[i-1];
	//for (int i=1; i<=n; i++) cerr<<A[i]<<" \n"[i==n];
	build(1, 1, n);
	/*
	debugv(seg[1])
	debugv(seg[2])
	debugv(seg[3])
	*/
	while (m--){
		cin>>t>>l>>r;
		if (t==1){
			cin>>k;
			fen.update(l, r, k);
			update(1, 1, n, l, fen.get(l)^fen.get(l-1));
			update(1, 1, n, r+1, fen.get(r+1)^fen.get(r));
			//for (int i=1; i<=n; i++) cerr<<fen.get(i)<<" \n"[i==n], update(1, 1, n, i, fen.get(i)^fen.get(i-1));
			continue ;
		}
		vector<int> vec=get(1, 1, n, l+1, r);
		add(vec, fen.get(l));
		cout<<(1<<vec.size())<<'\n';
		//debugv(vec)
		//break;
	}
	
	return 0;
}