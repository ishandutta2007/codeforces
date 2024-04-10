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

const int N = 52010;
const int S = 10;
const int D = 52;

struct node
{
	int c[S]={}, e[S]={};
	int f=0;
	bool g=0;
};
vector<node> t;

void add(string s){
	int i = 0;
	for(char c : s){
		c -= '0';
		if(!t[i].c[c]) t[i].c[c]=t.size(), t.emplace_back();
		i = t[i].c[c];
	}
	t[i].g = 1;
}

void make_dfa()
{
	t[0].f=-1;
	queue<tuple<int,int,int>> q;
	Loop(i,0,S) if(t[0].c[i]) {
		t[0].e[i] = t[0].c[i];
		q.emplace(0,i,t[0].c[i]);
	}
	while(q.size()){
		auto [p, c, i] = q.front(); q.pop();
		t[i].f = p? t[t[p].f].e[c]: 0;
		Loop(j,0,S) t[i].e[j] = t[i].c[j]? t[i].c[j]: t[t[i].f].e[j];
		Loop(j,0,S) if(t[i].c[j]) q.emplace(i, j, t[i].c[j]);
	}
}

const int mod = 1e9+7;
string s, x, y;
int n, d;
ll dp[D][N][2][2]; // len, vertex, good, prefix

void calc(string s){
	memset(dp, 0, sizeof dp);
	dp[0][0][0][1]=1;
	Loop(i,0,d)  Loop(v,0,t.size()) Loop(g,0,2) Loop(j,0,S) {
		dp[i+1][t[v].e[j]][g||t[t[v].e[j]].g][0] += dp[i][v][g][0];
		if(j < s[i]) dp[i+1][t[v].e[j]][g||t[t[v].e[j]].g][0] += dp[i][v][g][1];
		if(j == s[i]) dp[i+1][t[v].e[j]][g||t[t[v].e[j]].g][1] += dp[i][v][g][1];
		dp[i+1][t[v].e[j]][g||t[t[v].e[j]].g][0] %= mod;
		dp[i+1][t[v].e[j]][g||t[t[v].e[j]].g][1] %= mod;
	}
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);
	t.emplace_back();
	cin >> s >> x >> y;
	n = s.size();
	d = x.size();
	for(int i = 0; i+d/2 <= n; ++i) add(s.substr(i,d/2));
	for(char& c : x) c-='0';
	for(char& c : y) c-='0';
	make_dfa();
	ll ans = 0;
	calc(y);
	Loop(i,0,t.size()) ans += dp[d][i][1][0] + dp[d][i][1][1];
	calc(x);
	Loop(i,0,t.size()) ans -= dp[d][i][1][0];
	cout << (ans%mod+mod)%mod << '\n';
}