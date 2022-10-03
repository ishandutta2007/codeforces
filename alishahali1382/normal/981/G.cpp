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
const int mod = 998244353;
const int MAXN = 200010, LOG=20;

int _add(int x, int y){
	int res=x+y;
	if (res>=mod) res-=mod;
	return res;
}

int _mul(int x, int y){
	return 1ll*x*y%mod;
}

int n, m, k, u, v, x, y, t, a, b, l, r;
int seg[MAXN<<2], Add[MAXN<<2], Mul[MAXN<<2];
set<piii> st[MAXN];

void add_lazy(int id, int tl, int tr, int mul, int add){
	seg[id]=_add(_mul(seg[id], mul), _mul(add, tr-tl));
	Mul[id]=_mul(Mul[id], mul);
	Add[id]=_add(_mul(Add[id], mul), add);
}

void shift(int id, int tl, int tr){
	int mid=(tl+tr)>>1;
	add_lazy(id<<1, tl, mid, Mul[id], Add[id]);
	add_lazy(id<<1 | 1, mid, tr, Mul[id], Add[id]);
	Mul[id]=1;
	Add[id]=0;
}

void update(int id, int tl, int tr, int l, int r, int mul, int add){
	//if (id==1) cerr<<"update "<<l<<' '<<r<<' '<<mul<<' '<<add<<'\n';
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, tl, tr, mul, add);
		return ;
	}
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, l, r, mul, add);
	update(id<<1 | 1, mid, tr, l, r, mul, add);
	seg[id]=_add(seg[id<<1], seg[id<<1 | 1]);
}

int get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return 0;
	if (l<=tl && tr<=r) return seg[id];
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	return _add(get(id<<1, tl, mid, l, r), get(id<<1 | 1, mid, tr, l, r));
}

void split(int num, int x){
	auto it=--st[num].upper_bound({{x, inf}, 0});
	pii p=it->first;
	int tmp=it->second;
	if (p.first==x) return ;
	st[num].erase(it);
	st[num].insert({{p.first, x}, tmp});
	st[num].insert({{x, p.second}, tmp});
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=0; i<MAXN; i++) st[i].insert({{1, n+1}, 0});
	while (m--){
		cin>>t>>l>>r;
		r++;
		if (t==2) cout<<get(1, 1, n+1, l, r)<<'\n';
		else{
			cin>>x;
			//for (auto it:st[x]) debugp(it.first)
			split(x, l);
			split(x, r);
			//debug("splited")
			while (1){
				auto it=st[x].lower_bound({{l, l}, 0});
				if (it==st[x].end() || (*it).first.first==r) break ;
				pii p=it->first;
				if (it->second) update(1, 1, n+1, p.first, p.second, 2, 0);
				else update(1, 1, n+1, p.first, p.second, 1, 1);
				st[x].erase(it);
			}
			st[x].insert({{l, r}, 1});
		}
	}
	
	return 0;
}
/*
1 6
1 1 1 3
1 1 1 3
1 1 1 2
1 1 1 1
1 1 1 2
2 1 1


3 2
1 1 1 1
1 1 1 1

*/