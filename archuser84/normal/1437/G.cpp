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

const int N = 300'010;

struct node{
	int c[26]={};
	int f=0;
	int e[26]={};
	multiset<int,greater<int>> ms;
	int mx = -1;
}; vector<node> t;

int add(string s){
	int i = 0;
	for(char c : s){
		if(!t[i].c[c-'a']) t[i].c[c-'a'] = t.size(), t.emplace_back();
		i = t[i].c[c-'a'];
	}
	t[i].ms.insert(0);
	t[i].mx = 0;
	return i;
}

void make_dfa(){
	t[0].f = -1;
	vector<tuple<int,int,int>> q;
	Loop(i,0,26) if(t[0].c[i]){
		t[0].e[i] = t[0].c[i];
		q.emplace_back(0, i, t[0].c[i]);
	}
	for(int i = 0; i < q.size(); ++i){
		auto [p, c, v] = q[i];
		t[v].f = p? t[t[p].f].e[c]: 0;
		Loop(i,0,26) t[v].e[i] = t[v].c[i]? t[v].c[i]: t[t[v].f].e[i];
		Loop(i,0,26) if(t[v].c[i]) q.emplace_back(v, i, t[v].c[i]);
	}
	for(auto [p, c, v] : q)
		t[v].f = t[t[v].f].ms.size()? t[v].f: t[t[v].f].f;
}

int p[N];
int sus[N]; // AMOGUS
int n, m;

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	t.emplace_back();
	cin >> n >> m;
	Loop(i,0,n){
		string s;
		cin >> s;
		p[i] = add(s);
	}
	make_dfa();
	while(m--){
		int type;
		cin >> type;
		if(type==1){
			int i, x; cin >> i >> x; --i;
			t[p[i]].ms.erase(t[p[i]].ms.lower_bound(sus[i]));
			sus[i] = x;
			t[p[i]].ms.insert(x);
			t[p[i]].mx = *t[p[i]].ms.begin();
		} else {
			int ans = -1;
			int i = 0;
			string s; cin >> s;
			for(char c : s){
				c -= 'a';
				i = t[i].e[c];
				int j = i;
				while(j!=-1){
					ans = max(ans, t[j].mx);
					j = t[j].f;
				}
			}
			cout << ans << '\n';
		}
	}
}