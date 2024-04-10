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

int mod=1e9+1;

struct node{
	int cnt=0;
	int l=0, r=0;
}; vector<node> t;

int new_node(){t.emplace_back(); return t.size()-1;}

void add(ll p, int i=0, ll b=(ll)-1e9, ll e=(ll)2e9)
{
	++t[i].cnt;
	if(e-b==1) return;
	if(!t[i].l) t[i].l = new_node();
	if(!t[i].r) t[i].r = new_node();
	int m = (b+e)/2;
	if(m-1-t[t[i].l].cnt < p) add(p+t[t[i].l].cnt,t[i].r,m,e);
	else add(p,t[i].l,b,m);
}
ll get(ll p, int i=0, ll b=(ll)-1e9, ll e=(ll)2e9)
{
	if(e-b==1) return p-t[i].cnt;
	if(p < (b+e)/2) return  t[i].l? get(p,t[i].l,b,(b+e)/2): p;
	else            return (t[i].r? get(p,t[i].r,(b+e)/2,e): p)-(t[i].l?t[t[i].l].cnt:0);
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	new_node();
	int n;
	cin >> n;
	ll lst = 0;
	Loop(i,0,n)
	{
		int t, k;
		cin >> t >> k;
		add(t-i+1); add(t-i);
		while(k--){
			ll x;
			cin >> x;
			x = (x+lst)%mod;
			lst = get(x)+(i+1);
			cout << lst << '\n';
		}
	}
}