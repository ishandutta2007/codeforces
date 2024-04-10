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
set<int> lucky = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777, 4444, 4447, 4474, 4477, 4744, 4747, 4774, 4777, 7444, 7447, 7474, 7477, 7744, 7747, 7774, 7777, (int)1e9};

int t[N<<2];
int dis[N<<2];
int lzy[N<<2];

void addnode(int i, int x){if(x){t[i]=0; dis[i]-=x; lzy[i]+=x;}}
void ppg(int i){
	addnode(2*i+1,lzy[i]);
	addnode(2*i+2,lzy[i]);
	lzy[i] = 0;
}
void up(int i){t[i]=t[2*i+1]+t[2*i+2];dis[i]=min(dis[2*i+1],dis[2*i+2]);}

void add(int l, int r, int x, int i=0, int b=0, int e=N)
{
	if(l <= b && e <= r && x < dis[i]) return addnode(i,x);
	if(r <= b || e <= l) return;
	if(e-b == 1){
		lzy[i]+=x;
		t[i]=lucky.count(lzy[i]);
		dis[i] = *lucky.upper_bound(lzy[i])-lzy[i];
		return;
	}
	ppg(i);
	add(l,r,x,2*i+1,b,(b+e)/2);
	add(l,r,x,2*i+2,(b+e)/2,e);
	up(i);
}

int get(int l, int r, int i=0, int b=0, int e=N)
{
	if(l <= b && e <= r) return t[i];
	if(r <= b || e <= l) return 0;
	ppg(i);
	return get(l,r,2*i+1,b,(b+e)/2)+get(l,r,2*i+2,(b+e)/2,e);
}

int n, m;

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	fill(dis,dis+(N<<2),*lucky.begin());
	cin >> n >> m;
	Loop(i,0,n){
		int x;
		cin >> x;
		add(i,i+1,x);
	}
	while(m--){
		string s;
		int l, r;
		cin >> s >> l >> r; --l;
		if(s[0] == 'c') cout << get(l,r) << '\n';
		else {
			int x;
			cin >> x;
			add(l,r,x);
		}
	}
}