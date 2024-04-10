///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;

const int N = 300'010;

namespace seg
{
	pii t[N<<2];
	int lzy[N<<2];

	void ppg(int i){
		t[2*i+1].first += lzy[i];
		t[2*i+2].first += lzy[i];
		lzy[2*i+1] += lzy[i];
		lzy[2*i+2] += lzy[i];
		lzy[i] = 0;
	}

	void init(int i = 0, int b=0, int e=N){
		if(e-b==1) {t[i].second=b; return;}
		init(2*i+1,b,(b+e)/2);
		init(2*i+2,(b+e)/2,e);
		t[i] = max(t[2*i+1], t[2*i+2]);
	}

	void add(int l, int r, int x, int i=0, int b=0, int e=N){
		if(l <= b && e <= r) {t[i].first += x; lzy[i] += x; return;}
		if(r <= b || e <= l) return;
		ppg(i);
		add(l,r,x,2*i+1,b,(b+e)/2);
		add(l,r,x,2*i+2,(b+e)/2,e);
		t[i] = max(t[2*i+1], t[2*i+2]);
	}
}

int n;
int l[N], v[N], r[N];
vector<pair<pii,int>> padoru[N];

pair<int,pii> ans;

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop(i,0,n) {
		cin >> l[i] >> v[i] >> r[i];
		padoru[l[i]].push_back({{v[i], r[i]+1},1});
		padoru[v[i]+1].push_back({{v[i], r[i]+1},-1});
	}
	seg::init();
	Loop(i,0,N){
		for(auto [ivl, x] : padoru[i]) seg::add(ivl.first,ivl.second,x);
		ans = max(ans, pair<int,pii>{seg::t[0].first,pii{i, seg::t[0].second}});
	}
	cout << ans.first << '\n';
	int L = ans.second.first;
	int R = ans.second.second;
	Loop(i,0,n)
		if(l[i] <= L && L <= v[i] && v[i] <= R && R <= r[i])
			cout << i+1 << ' ';
	cout << '\n';
}