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

#pragma GCC optimize("unroll-loops")

const int alpha = 2;
const int N = 800;

struct node{
	int c[alpha]={}, e[alpha]={};
	int f=0;
	int leaf=0;
} t[10'000'010]; int ts = 1;

vector<int> padoru[N];
int nero[N];

void add(char* s, int p){
	int i = 0;
	for(int z = 0; s[z]; ++z){
		if(!t[i].c[s[z]-'a']) t[i].c[s[z]-'a'] = ts++;
		i = t[i].c[s[z]-'a'];
		padoru[p].push_back(i);
	}
	nero[p] = i;
	t[i].leaf = p+1;
}

void make_dfa(){
	t[0].f = -1;
	queue<tuple<int,int,int>> q;
	vector<int> dio;

	Loop(i,0,alpha) if(t[0].c[i]){
		t[0].e[i] = t[0].c[i];
		q.emplace(0, i, t[0].c[i]);
	}
	while(q.size()){
		auto [p, c, v] = q.front(); q.pop();
		dio.push_back(v);
		t[v].f = p? t[t[p].f].e[c]: 0;
		Loop(i,0,alpha) t[v].e[i] = t[v].c[i]? t[v].c[i]: t[t[v].f].e[i];
		Loop(i,0,alpha) if(t[v].c[i]) q.emplace(v, i, t[v].c[i]);
	}

	for(int v : dio){
		if(!t[t[v].f].leaf)
			t[v].f = t[t[v].f].f;
	}
}

bool Z[2*N];
vector<int> A[N];
int mch1[N];
int mch2[N];
int vis[N];
int p[N];
int n;

bool bfs(int s){
	vector<int> dio;
	queue<int> q;
	p[s] = -1;
	q.push(s); dio.push_back(s);
	while(q.size()){
		int v = q.front(); q.pop();
		for(int u : A[v]){
			if(vis[u]==s) continue;
			vis[u]=s;
			if(mch2[u]==-1){
				while(v!=-1){
					mch2[u] = v;
					swap(u, mch1[v]);
					v = p[v];
				}
				return 1;
			}
			dio.push_back(u+N); u=mch2[u];
			dio.push_back(u); q.push(u); p[u]=v;
		}
	}
	for(int v : dio) Z[v]=1;
	return 0;
}

char s[10'000'010];

bitset<10'000'010> visb;
int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop(i,0,n){
		cin >> s;
		add(s,i);
	}
	make_dfa();
	Loop(i,0,n) {
		vector<int> dio;
		for(int j : padoru[i]){
			int v = j;
			while(v != -1 && !visb[v]){
				visb[v] = 1;
				dio.push_back(v);
				if(t[v].leaf && t[v].leaf-1 != i)
					A[i].push_back(t[v].leaf-1);
				v = t[v].f;
			}
		}
		for(int i : dio) visb[i] = 0;
	}
	memset(vis, -1, sizeof vis);
	memset(mch1, -1, sizeof vis);
	memset(mch2, -1, sizeof vis);
	int ans = n;
	Loop(i,0,n) {
		ans -= bfs(i);
	}
	cout << ans << '\n';
	Loop(i,0,n) if(Z[i] && !Z[i+N])
		cout << i+1 << ' ';
	cout << '\n';
	//cout << (double)clock()/CLOCKS_PER_SEC << '\n';
}