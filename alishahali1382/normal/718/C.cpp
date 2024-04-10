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

struct MAT12: pll{
	MAT12(){ first=second=0;}
	void reset(){ first=second=0;}
	void operator =(pll M){ first=M.first;second=M.second;}
	void operator =(MAT12 M){ first=M.first;second=M.second;}
	MAT12 operator +(MAT12 M){
		MAT12 out;
		out.first=(first+M.first)%mod;
		out.second=(second+M.second)%mod;
		return out;
	}
	void relax(){ first%=mod;second%=mod;}
} seg[MAXN<<2];

struct MAT22: pair<MAT12, MAT12>{
	MAT22(){ first.reset();second.reset();}
	void operator =(MAT22 &M){ first=M.first;second=M.second;}
	void relax(){ first.relax();second.relax();}
	void operator *=(MAT22 M){
		int a11=first.first, a12=first.second, a21=second.first, a22=second.second;
		first.first=a11*M.first.first + a21*M.first.second;
		first.second=a12*M.first.first + a22*M.first.second;
		second.first=a11*M.second.first + a21*M.second.second;
		second.second=a12*M.second.first + a22*M.second.second;
		relax();
	}
} T;

void operator *=(MAT12 & M, MAT22 &T){
	ll x=M.first, y=M.second;
	M.first=x*T.first.first + y*T.first.second;
	M.second=x*T.second.first + y*T.second.second;
	M.relax();
}

void operator ^=(MAT22 &M, ll tavan){
	MAT22 tmp=M;
	tavan--;
	for (; tavan; tavan>>=1, tmp*=tmp) if (tavan&1) M*=tmp;
}

int n, m, k, u, v, x, y, t, a, b, l, r, type;
ll lazy[MAXN<<2];

void build(int id, int tl, int tr){
	if (tl==tr){
		seg[id].second=1;
		return ;
	}
	int mid=(tl+tr)>>1;
	build(id<<1, tl, mid);
	build(id<<1 | 1, mid+1, tr);
	seg[id]=seg[id<<1] + seg[id<<1 | 1];
}

void shift(int id){
	if (!lazy[id]) return ;
	lazy[id<<1]+=lazy[id];
	lazy[id<<1 | 1]+=lazy[id];
	MAT22 M=T;
	M^=lazy[id];
	lazy[id]=0;
	seg[id<<1]*=M;
	seg[id<<1 | 1]*=M;
}

MAT22 TT;

void update(int id, int tl, int tr, int l, int r, int x){
	if (r<tl || tr<l) return ;
	if (l<=tl && tr<=r){
		lazy[id]+=x;
		seg[id]*=TT;
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, l, r, x);
	update(id<<1 | 1, mid+1, tr, l, r, x);
	seg[id]=seg[id<<1] + seg[id<<1 | 1];
}

MAT12 get(int id, int tl, int tr, int l, int r){
	if (r<tl || tr<l){
		MAT12 out;
		return out;
	}
	if (l<=tl && tr<=r) return seg[id];
	shift(id);
	int mid=(tl+tr)>>1;
	return get(id<<1, tl, mid, l, r) + get(id<<1 | 1, mid+1, tr, l, r);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	T.first.second=T.second.first=T.second.second=1;
	cin>>n>>m;
	build(1, 1, n);
	for (int i=1; i<=n; i++){
		cin>>x;
		TT=T;
		TT^=x;
		update(1, 1, n, i, i, x);
	}
	
	while (m--){
		cin>>type>>l>>r;
		if (type==2) cout<<get(1, 1, n, l, r).first%mod<<'\n';
		else{
			cin>>x;
			TT=T;
			TT^=x;
			update(1, 1, n, l, r, x);
		}
	}
	
	return 0;
}