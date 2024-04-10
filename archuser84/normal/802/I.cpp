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

int len[2*N];
array<int,26> nxt[2*N];
int link[2*N];
bool ac[2*N];
int sz = 0;
int last;

int new_state(){
	++sz;
	nxt[sz] = {};
	link[sz] = 0;
	ac[sz] = 0;
	len[sz] = 0;
	return sz;
} void init(){sz=0;last=new_state();}

void append(char c)
{
	c -= 'a';
	int p = last;
	last = new_state();
	len[last] = len[p]+1;
	while(p && !nxt[p][c]){
		nxt[p][c] = last;
		p = link[p];
	}
	int q = nxt[p][c];
	if(!p)
		link[last] = 1;
	else if(len[q] == len[p]+1)
		link[last] = q;
	else {
		int cl = new_state();
		nxt[cl] = nxt[q];
		link[cl] = link[q];
		len[cl] = len[p]+1;
		link[last] = link[q] = cl;
		while(p && nxt[p][c]==q){
			nxt[p][c] = cl;
			p = link[p];
		}
	}
}

void find_ac()
{
	int p = last;
	while(p){
		ac[p]=1;
		p = link[p];
	}
}

vector<int> A[2*N];
ll ans = 0;
int cnt[2*N];

ll dfs(int v)
{
	ll cnt = ::cnt[v];
	for(int u : A[v])
		cnt += dfs(u);
	ans += cnt*cnt*(len[v]-len[link[v]]);
	return cnt;
}

void solve()
{
	string s;
	cin >> s;
	init();
	for(char c : s)
		append(c);
	//Loop(i,1,sz+1) cout << link[i] << ' ';
	Loop(i,1,sz+1) A[i].clear(), cnt[i]=0;
	int q = 1;
	for(char c : s){
		q = nxt[q][c-'a'];
		cnt[q]++;
	}
	Loop(i,1,sz+1){
		A[link[i]].push_back(i);
	}
	ans = 0;
	dfs(1);
	cout << ans << '\n';
}


int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) solve();
}