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

const int N = 150'010;
multiset<int> ms;
int ans = 0;
int s[N], b[N];
int mch[N];
int n, len, h;

vector<int> seg[N<<2];

void add(int l, int r, int p, int i=0, int b=0, int e=n+1-len){
	if(l <= b && e <= r){seg[i].push_back(p); return;}
	if(r <= b || e <= l) return;
	add(l,r,p,2*i+1,b,(b+e)/2);
	add(l,r,p,2*i+2,(b+e)/2,e);
}

void dfs(int v=0, int b=0, int e=n+1-len){
	Loop(i,0,seg[v].size()){
		auto it = ms.lower_bound(h-s[seg[v][i]]);
		if(it==ms.end()) {
			Loop(j,0,i)
				ms.insert(mch[seg[v][j]]);
			return;
		}
		mch[seg[v][i]] = *it;
		ms.erase(it);
	}

	if(e-b==1)
		++ans;
	else {dfs(2*v+1,b,(b+e)/2); dfs(2*v+2,(b+e)/2,e);}

	for(int x : seg[v]) ms.insert(mch[x]);
	return;
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> len >> h;
	Loop(i,0,len) cin >> b[i], ms.insert(b[i]);
	Loop(i,0,n) cin >> s[i], add(max(0ll, i-len+1), i+1, i);
	dfs();
	cout << ans << '\n';
}