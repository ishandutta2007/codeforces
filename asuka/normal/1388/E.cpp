#include<bits/stdc++.h>
#define ll long long
#define N 2015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define db double
using namespace std;
struct line{
	db k,b;
	db get(db x){return k*x + b;}
	bool operator <(const line &o) const{
		if(k != o.k) return k < o.k;
		return b > o.b;
	}
	bool operator == (const line &o) const{
		return k == o.k;
	}
};
struct ConvexHull{
	int sz = 0;
	vector<line> u,H;
	db inter(int l1,int l2){
		return db(H[l1].b-H[l2].b)/db(H[l2].k-H[l1].k);
	}
	bool bad(int l1,int l2,int l3){
		db l = inter(l1,l3),r = inter(l1,l2);
		return l < r;
	}
	void add(line x){u.pb(x);}
	void insert(line x){
		H[sz++] = x;
		while(sz > 2 && bad(sz-3,sz-2,sz-1)){
			H[sz-2] = H[sz-1]; --sz;
		}
	}
	void build(){
		sort(all(u));
		u.erase(unique(all(u)),u.end());
		H.resize(u.size()+1);
		for(auto x:u) insert(x);
	}
	db query(db x){
		int l = 0,r = sz-1;
		while(l < r){
			int mid = (l+r)>>1;
			if(H[mid].get(x) <= H[mid+1].get(x)){
				l = mid+1;
			}else r = mid;
		} 
		return H[l].get(x);
	}
};
struct seg{
	int xl,xr,y;
}s[N];
struct Frac {
    int64_t x, y;
    Frac(int64_t x = 0, int64_t y = 1) : x(x), y(y) {norm();}
    db to_double(){return (db)x/(db)y;}
    void norm() {
        if (y < 0) {
            y = -y;
            x = -x;
        }
    }
};
bool operator<(const Frac &lhs, const Frac &rhs) {
    return 1ll * lhs.x * rhs.y < 1ll * rhs.x * lhs.y;
}
vector<pair<Frac,int>> e;
vector<db> res;
bool cmp(seg a,seg b){
	return a.y < b.y;
}
int n;
ConvexHull Max,Min;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin >> n;
	rep(i,1,n) cin>>s[i].xl>>s[i].xr>>s[i].y;
	sort(s+1,s+n+1,cmp);
	rep(i,1,n) rep(j,i+1,n){
		if(s[i].y == s[j].y) continue;
		int dy = (s[j].y - s[i].y);
		assert(dy >= 0.0);
		auto l = Frac(s[i].xl - s[j].xr,dy),r = Frac(s[i].xr - s[j].xl,dy);
		e.pb(mp(l,1)); e.pb(mp(r,-1));
	}
	sort(all(e));
	int cur = 0;
	for(auto u:e){
		bool ok = cur==0;
		cur += u.se; ok |= cur==0;
		if(ok) res.pb(u.fi.to_double());
	}
	if(res.empty()) res.pb(0);
	// printf("OK\n");
	rep(i,1,n) 
		Min.add((line){-1.0*s[i].y,-1.0*s[i].xl}),
		Max.add((line){1.0*s[i].y,1.0*s[i].xr});
	Max.build(); Min.build();
	// printf("OK\n");
	db ans = 1e50;
	for(auto x:res){
		db ax,in;
		ax = Max.query(x); in = -Min.query(x);
		ans = min(ans,ax-in);
	}
	cout << fixed << setprecision(9) << ans;
	return 0;
}