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
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=500010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int Mn[MAXN<<2], Mx[MAXN<<2], lazy[MAXN<<2];
ll seg[MAXN<<2], ans;
string S;

void add_lazy(int id, int len, int val){
	lazy[id]+=val;
	Mn[id]+=val;
	Mx[id]+=val;
	seg[id]+=1ll*val*len;
}
void shift(int id, int tl, int tr){
	if (!lazy[id]) return ;
	int mid=(tl+tr)>>1;
	add_lazy(id<<1, mid-tl, lazy[id]);
	add_lazy(id<<1 | 1, tr-mid, lazy[id]);
	lazy[id]=0;
}
void Add(int id, int tl, int tr, int l, int r, int val){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, tr-tl, val);
		return ;
	}
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	Add(id<<1, tl, mid, l, r, val);
	Add(id<<1 | 1, mid, tr, l, r, val);
	seg[id]=seg[id<<1] + seg[id<<1 | 1];
	Mn[id]=min(Mn[id<<1], Mn[id<<1 | 1]);
	Mx[id]=max(Mx[id<<1], Mx[id<<1 | 1]);
}
void Maximize(int id, int tl, int tr, int l, int r, int val){
	if (r<=tl || tr<=l || val<=Mn[id]) return ;
	if (l<=tl && tr<=r && Mn[id]==Mx[id]){
		add_lazy(id, tr-tl, val-Mx[id]);
		return ;
	}
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	Maximize(id<<1, tl, mid, l, r, val);
	Maximize(id<<1 | 1, mid, tr, l, r, val);
	seg[id]=seg[id<<1] + seg[id<<1 | 1];
	Mn[id]=min(Mn[id<<1], Mn[id<<1 | 1]);
	Mx[id]=max(Mx[id<<1], Mx[id<<1 | 1]);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>S;
	int last=-1;
	for (int i=0; i<n; i++){
		if (S[i]=='1'){
			Maximize(1, 0, n, 0, last+1, i-last);
			Add(1, 0, n, last+1, i+1, +1);
		}
		else last=i;
		ans+=seg[1];
	}
	cout<<ans<<"\n";
	
	return 0;
}