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
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 100'010;
ll s[N];
vector<int> A[N];
vector<int> ff[N]; // Foo Fighters
vector<int> jolyne[N];
int h[N];
int st[N], ft[N];
int n, m;

void dfs(int v, int h, int& t){
	::h[v] = h;
	ff[h].push_back(t);
	jolyne[h].push_back(s[v]);
	st[v] = t++;
	for(int u : A[v])
		dfs(u, h+1, t);
	ft[v] = t;
}

struct seg
{
	vector<int>* t;
	vector<int> v;

	#define all(v) v.begin(), v.end()

	void build(int i, int b, int e){
		if(e-b == 1){t[i] = {v[b]}; return;}
		build(2*i+1, b, (b+e)/2);
		build(2*i+2, (b+e)/2, e);
		merge(all(t[2*i+1]), all(t[2*i+2]), back_inserter(t[i]));
	}

	void init(const vector<int>& _v) {
		v = _v;
		map<ll,int> mp;
		Loop(i,0,v.size()){
			auto x = v[i];
			v[i] = mp.count(v[i])? mp[v[i]]: -1;
			mp[x] = i;
		}
		t = new vector<int>[v.size()<<2];
		build(0,0,v.size());
	}

	int get(int l, int r, int i, int b, int e){
		if(l <= b && e <= r) return lower_bound(all(t[i]), l) - t[i].begin();
		if(r <= b || e <= l) return 0;
		return get(l,r,2*i+1,b,(b+e)/2)+get(l,r,2*i+2,(b+e)/2,e);
	}
	int get(int l, int r){return l>=r?0:get(l,r,0,0,v.size());}
} S[N];

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	vector<int> joestar;
	Loop(i,0,n){
		string s; int p;
		cin >> s >> p;
		::s[i] = hash<string>()(s);
		(p? A[p-1]: joestar).push_back(i);
	}
	int tm = 0;
	for(int v : joestar) dfs(v,0,tm);
	int H=n;
	Loop(i,0,n) {if(jolyne[i].empty()) {H=i; break;} S[i].init(jolyne[i]);}
	int t;
	cin >> t;
	while(t--){
		int v, k;
		cin >> v >> k; --v;
		k += h[v];
		if(k >= H) {cout << "0\n"; continue;}
		int l = lower_bound(all(ff[k]), st[v])-ff[k].begin();
		int r = lower_bound(all(ff[k]), ft[v])-ff[k].begin();
		cout << S[k].get(l,r) << '\n';
	}
}