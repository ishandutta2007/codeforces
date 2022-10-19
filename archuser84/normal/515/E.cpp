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

const int N = 100'010;
ll d[N], h[N];
ll pos[N], neg[N];
ll sum = 0;
const ll inf = 1e18;
int n, m;

struct node{
	ll mp=0, mn=0, ans=0;
} t[N<<2];

node merge(const node& a, const node& b){
	return {max(a.mp,b.mp),max(a.mn,b.mn),max({a.ans,b.ans,b.mp+a.mn})};
}

void init(int i=0, int b=0, int e=n){
	if(e-b==1){t[i] = {pos[b], neg[b], -inf}; return;}
	init(2*i+1,b,(b+e)/2);
	init(2*i+2,(b+e)/2,e);
	t[i] = merge(t[2*i+1], t[2*i+2]);
}

node get(int l, int r, int i=0, int b=0, int e=n){
	if(l <= b && e <= r) return t[i];
	if(r <= b || e <= l) return {-inf,-inf,-inf};
	return merge(get(l,r,2*i+1,b,(b+e)/2),get(l,r,2*i+2,(b+e)/2,e));
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m;
	Loop(i,0,n) cin >> d[i], pos[i] = sum, neg[i] = -sum, sum += d[i];
	Loop(i,0,n) cin >> h[i], pos[i] += 2*h[i], neg[i] += 2*h[i];
	init();
	while(m--){
		int l, r;
		cin >> l >> r; --l;
		if(l < r){
			auto t1 = get(0,l);
			auto t2 = get(r,n);
			cout << max({t1.ans,t2.ans,t1.mp+t2.mn+sum}) << '\n';
		} else {
			cout << get(r,l).ans << '\n';
		}
	}
}