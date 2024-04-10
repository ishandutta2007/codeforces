///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 70'010;
const int S = (N+100)/5;
vector<pii> a; int w[N];
bitset<N> bs[S]; // bullshit haha
bool rt[N];
int nxt[N];
int mx;
int n, s;

pair<bool, vector<int>> solve_ssp(vector<pii> v, int s)
{
	auto do_for = [&](int k){
		bs[0].reset(); bs[0] = 1;
		Loop(i,0,k) bs[(i+1)%S] = bs[i%S] | (bs[i%S]<<v[i].first);
	};
	vector<int> ans;
	int n = v.size();
	do_for(n);
	if(!bs[n%S][s]) return {};
	LoopR(i,0,n){
		if(n-i==S){n-=S; do_for(n);}
		if(!bs[i%S][s]) {s -= v[i].first; ans.push_back(v[i].second);}
	}
	return {1, ans};
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> s;
	Loop(i,0,n) cin >> w[i], a.push_back({w[i],i});
	sort(a.begin(),a.end()); mx = a.back().second; a.pop_back();
	if(s < w[mx]) Kill(-1); s -= w[mx];
	auto [b, ans] = solve_ssp(a, s);
	if(!b) Kill(-1);
	a.push_back({w[mx],mx});
	for(int v : ans) rt[v] = 1; rt[mx]=1;
	memset(nxt,-1,sizeof nxt);
	Loop(i,0,a.size()){
		if(!rt[a[i].second])
			nxt[a[i+1].second] = a[i].second;
	}
	Loop(i,0,n){
		cout << w[i]-(nxt[i]==-1?0:w[nxt[i]]) << ' ';
		nxt[i]==-1? cout << "0\n": cout << "1 " << nxt[i]+1 << '\n';
	}
}