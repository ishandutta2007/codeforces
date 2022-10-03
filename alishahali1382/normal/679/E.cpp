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
const int MAXN = 200010;

struct SEGMENT{
	pll seg[MAXN<<2];
	ll lazy1[MAXN<<2];
	ll lazy2[MAXN<<2];
	bool mark[MAXN<<2];
	
	pll build(int id, int tl, int tr, ll A[]){
		if (tr-tl==1) return seg[id]={A[tl], -tl};
		int mid=(tl+tr)>>1;
		return seg[id]=max(build(id<<1, tl, mid, A), build(id<<1 | 1, mid, tr, A));
	}
	
	void set_lazy(int id, ll val){
		lazy2[id]=0;
		lazy1[id]=val;
		mark[id]=1;
		seg[id].first=val;
	}
	
	void add_lazy(int id, ll val){
		if (mark[id]) lazy1[id]+=val;
		else lazy2[id]+=val;
		seg[id].first+=val;
	}
	
	void shift(int id){
		if (!mark[id] && !lazy2[id]) return ;
		if (mark[id]){
			set_lazy(id<<1, lazy1[id]);
			set_lazy(id<<1 | 1, lazy1[id]);
			mark[id]=0;
			return ;
		}
		add_lazy(id<<1, lazy2[id]);
		add_lazy(id<<1 | 1, lazy2[id]);
		lazy2[id]=0;
	}
	
	void Add(int id, int tl, int tr, int l, int r, ll val){
		if (tr<=l || r<=tl) return ;
		if (l<=tl && tr<=r){
			add_lazy(id, val);
			return ;
		}
		shift(id);
		int mid=(tl+tr)>>1;
		Add(id<<1, tl, mid, l, r, val);
		Add(id<<1 | 1, mid, tr, l, r, val);
		seg[id]=max(seg[id<<1], seg[id<<1 | 1]);
	}
	
	void Set(int id, int tl, int tr, int l, int r, ll val){
		if (tr<=l || r<=tl) return ;
		if (l<=tl && tr<=r){
			set_lazy(id, val);
			return ;
		}
		shift(id);
		int mid=(tl+tr)>>1;
		Set(id<<1, tl, mid, l, r, val);
		Set(id<<1 | 1, mid, tr, l, r, val);
		seg[id]=max(seg[id<<1], seg[id<<1 | 1]);
	}
	
	ll Get(int id, int tl, int tr, int pos){
		if (tr-tl==1) return seg[id].first;
		shift(id);
		int mid=(tl+tr)>>1;
		if (pos<mid) return Get(id<<1, tl, mid, pos);
		return Get(id<<1 | 1, mid, tr, pos);
	}
} seg1, seg2;

ll n, m, k, u, v, x, y, t, l, r;
ll A[MAXN];
ll nxt[MAXN];
bool mark[MAXN];
set<pii> st;

void split(int x){
	if (x>n) return ;
	//if (mark[x]) return ;
	pii p=*--st.upper_bound({x, inf});
	if (p.first==x) return ;
	st.erase(p);
	st.insert({p.first, x});
	st.insert({x, p.second});
	nxt[x]=nxt[p.first];
	//mark[x]=1;
}

void relax(){
	while (seg2.seg[1].first>0){
		pii p=*--st.upper_bound({-seg2.seg[1].second, inf});
		seg2.Add(1, 1, n+1, p.first, p.second, -nxt[p.first]*41);
		nxt[p.first]*=42;
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i];
	seg1.build(1, 1, n+1, A);
	seg2.build(1, 1, n+1, A);
	seg2.Add(1, 1, n+1, 1, n+1, -1);
	for (int i=1; i<=n; i++) st.insert({i, i+1}), nxt[i]=1;
	
	while (m--){
		relax();
		cin>>t;
		if (t==1){
			cin>>x;
			cout<<seg1.Get(1, 1, n+1, x)<<'\n';
			continue ;
		}
		cin>>l>>r>>x;r++;
		split(l);
		if (r<=n) split(r);
		
		if (t==2){
			seg1.Set(1, 1, n+1, l, r, x);
			while (1){
				auto it=st.lower_bound({l, l});
				if (it==st.end() || (it->first)==r) break ;
				st.erase(it);
			}
			st.insert({l, r});
			nxt[l]=1;
			seg2.Set(1, 1, n+1, l, r, x-1);
			continue ;
		}
		while (1){
			seg1.Add(1, 1, n+1, l, r, x);
			seg2.Add(1, 1, n+1, l, r, x);
			relax();
			if (seg2.seg[1].first<0) break ;
		}
		
	}
	
	return 0;
}