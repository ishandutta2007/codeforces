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

#define int ll

const int N = 200'010;
int a[N]; set<int> s;
int n, k, d;

namespace seg
{
	int t[N<<2];
	int lzy[N<<2];

	void tag(int i, int x){t[i]+=x;lzy[i]+=x;}
	void ppg(int i){tag(2*i+1,lzy[i]);tag(2*i+2,lzy[i]);lzy[i]=0;}

	void add(int l, int r, int x, int i=0, int b=0, int e=N){
		if(l <= b && e <= r) return tag(i,x);
		if(r <= b || e <= l) return;
		ppg(i);
		add(l,r,x,2*i+1,b,(b+e)/2);
		add(l,r,x,2*i+2,(b+e)/2,e);
		t[i] = min(t[2*i+1],t[2*i+2]);
	}
	int get(int l, int r, int x, int i=0, int b=0, int e=N){
		if(t[i] >= x) return N;
		if(e-b==1) return b;
		ppg(i);
		int ans = N;
		if(l < (b+e)/2) ans = get(l,r,x,2*i+1,b,(b+e)/2);
		if((b+e)/2 < r && ans == N) ans = get(l,r,x,2*i+2,(b+e)/2,e);
		return ans;
	}
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> k >> d;
	int ansl=0, ansr=0;
	if(d == 0){
		int cnt = 0, lst = 0;
		for(int l=0,r=0; r<n;){
			int x; cin >> x;
			if(lst != x){l = r; lst = x;}
			++r;
			if(r-l > ansr-ansl){
				ansl = l;
				ansr = r;
			}
		}
		cout << ansl+1 << ' ' << ansr << '\n';
		return 0;
	}
	int lst = 0;
	vector<pll> ls = {{-1, -1}};
	vector<pll> mr = {{-1, 1e15}};
	for(int l=0,r=0; r<n;){
		int x; cin >> x; x += 1e9+10;
		if(x%d != lst){l=r; s.clear(); lst = x%d;}
		x /= d; a[r] = x;
		while(s.count(x)) s.erase(a[l++]);
		s.insert(x);

		// update seg
		seg::add(r,r+1,r);
		while(mr.back().second <= a[r]){
			seg::add(mr[mr.size()-2].first+1, mr.back().first+1, a[r] - mr.back().second);
			mr.pop_back();
		} mr.emplace_back(r, a[r]);
		while(ls.back().second >= a[r]){
			seg::add(ls[ls.size()-2].first+1, ls.back().first+1, ls.back().second - a[r]);
			ls.pop_back();
		} ls.emplace_back(r, a[r]);
		++r;

		// update ans
		int tmp = seg::get(l,r,r+k);
		if(r-tmp > ansr-ansl){
			ansl = tmp;
			ansr = r;
		}
	}
	cout << ansl+1 << ' ' << ansr << '\n';
}

// max - min - cnt + 1 <= k
// max - min - (r-l) + 1 <= k
// max-min+l < r+k