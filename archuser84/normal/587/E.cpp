///
///   You fell for it, fool!
///   Thunder Cross Split Attack!
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;

const int N = 200'010;
int a[N];
int n, q;

namespace seg
{
	typedef vector<int> node;
	node t[N<<2];
	int lzy[N<<2];

	void trim(node& v)
	{
		for(int i = 0; i < v.size(); ++i){
			int x = v[i], y = x&-x;
			for(int j = i+1; j < v.size(); ++j){
				v[j] = v[j]&y? v[j]^x: v[j];
				if(v[j]==0){
					swap(v[j], v.back());
					v.pop_back();
					--j;
				}
			}
		}
	}

	bool can(node& v, int x){
		for(int y : v)
			x = x&(y&-y)? x^y: x;
		return !x;
	}

	node merge(node v, const node& u){
		for(int x : u)
			v.push_back(x);
		trim(v);
		return v;
	}

	void lazy(int i, int x){lzy[i] ^= x; for(int& y : t[i]) y ^= y<0?x:0; trim(t[i]);}

	void ppg(int i){
		lazy(2*i+1, lzy[i]);
		lazy(2*i+2, lzy[i]);
		lzy[i] = 0;
	}

	void init(int i = 0, int b = 0, int e = N)
	{
		lzy[i] = 0;
		if(e-b == 1) {t[i] = {a[b]+INT_MIN}; return;}
		init(2*i+1,b,(b+e)/2);
		init(2*i+2,(b+e)/2,e);
		t[i] = merge(t[2*i+1], t[2*i+2]);
	}

	node get(int l, int r, int i = 0, int b = 0, int e = N)
	{
		if(l <= b && e <= r) return t[i];
		if(r <= b || e <= l) return {};
		ppg(i);
		return merge(get(l,r,2*i+1,b,(b+e)/2),get(l,r,2*i+2,(b+e)/2,e));
	}

	void up(int l, int r, int x, int i = 0, int b = 0, int e = N)
	{
		if(l <= b && e <= r) return lazy(i, x);
		if(r <= b || e <= l) return;
		ppg(i);
		up(l,r,x,2*i+1,b,(b+e)/2);
		up(l,r,x,2*i+2,(b+e)/2,e);
		t[i] = merge(t[2*i+1],t[2*i+2]);
	}
}
using namespace seg;

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> q;
	Loop(i,0,n) cin >> a[i];
	init();
	while(q--)
	{
		int t,l,r;
		cin>>t>>l>>r;--l;
		if(t==1){
			int x;
			cin >> x;
			up(l,r,x);
		} else {
			auto ans = get(l,r);
			trim(ans);
			cout << (1<<(ans.size()-can(ans,INT_MIN))) << '\n';
		}
	}
}