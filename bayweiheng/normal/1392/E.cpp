#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>

using namespace std;

typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef tuple<int,int,int> iii;

#define pb push_back
#define ctz __builtin_ctz
#define pct __builtin_popcount
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);++i)

struct ufds {
	int n;
	vi p,ranks;
	ufds(int n):n(n) {
		p.resize(n);
		ranks.resize(n,0);
		rep(i,n) p[i]=i;
	}
	int find(int i) {
		return i==p[i] ? i : p[i]=find(p[i]);
	}
	bool unionset(int i,int j) {
		int x=find(i),y=find(j);
		if(x==y) return false;
		if(ranks[x]<ranks[y]) {
			p[x]=y;
		} else {
			p[y]=x;
			if(ranks[x]==ranks[y]) ++ranks[x];
		}
		return true;
	}
};

struct fw {
	int n;
	vll a;
	fw(int n) {
		a.resize(n+1, 0);
	}
	void update(int i, int val) {
		while(i<=n) {
			a[i]+=val;
			i+=i&(-i);
		}
	}
	ll query(int i) {
		ll ans=0;
		while(i) {
			ans+=a[i];
			i-=i&(-i);
		}
		return ans;
	}
	ll query(int i,int j) {
		return query(j) - query(i-1);
	}
};

struct segtree {
	int n;
	vll lo,hi,rmin,delta; // represents responsible ranges
	ll* a;
	ll inf=1e18;
	segtree(int n,ll* a):n(n),a(a) {
		lo.resize(4*n+1,0); // 2n-1 nodes, but indexing system requires *2
		hi.resize(4*n+1,0);
		rmin.resize(4*n+1,0);
		delta.resize(4*n+1,0);
		init(1,0,n-1);
	}
	void increment(int l,int r,ll val) {
		increment(1,l,r,val);
	}
	ll minimum(int l,int r) {
		return minimum(1,l,r);
	}
	void init(int i,int l,int r) {
		lo[i]=l;
		hi[i]=r;
		if(l==r) {
			rmin[i]=a[l];
			return;
		}
		int m=(l+r)/2;
		init(2*i,l,m);
		init(2*i+1,m+1,r);
		update(i);
	}
	void prop(int i) {
		delta[2*i] += delta[i];
		delta[2*i+1] += delta[i];
		delta[i]=0;
	}
	void update(int i) { // updates ans
		rmin[i] = min(rmin[2*i]+delta[2*i], rmin[2*i+1]+delta[2*i+1]);
	}
	void increment(int i,int l,int r,int val) { // don't need this for static rmq
		if(r<lo[i] || hi[i]<l) return;
		if(l<=lo[i] && hi[i]<=r) { // if updating whole node
			delta[i] += val;
			return;
		}
		prop(i); // at start of every recursion
		increment(2*i,l,r,val);
		increment(2*i+1,l,r,val);
		update(i); // end of every recursion
	}
	ll minimum(int i,int l,int r) { // don't need this for global min queries, answer is always rmin[1]+delta[1]
		if(r<lo[i] || hi[i]<l) return inf;
		if(l<=lo[i] && hi[i]<=r) return rmin[i]+delta[i];
		prop(i);
		int minleft = minimum(2*i,l,r);
		int minright = minimum(2*i+1,l,r);
		update(i);
		return min(minleft,minright);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n;
    ll a[n][n];
    rep(i,n) {
    	rep(j,n) {
    		if(i & 1) a[i][j]=0;
    		else a[i][j] = 1LL << (i+j);
    	}
    }
    rep(i,n) {
    	cout<<a[i][0];
    	for(int j=1;j<n;++j) {
    		cout<<" "<<a[i][j];
    	}
    	cout<<endl;
    }
    cin>>q;
    ll k;
    while(q--) {
    	cin>>k;
    	int i=0,j=0;
    	while(true) {
    		assert(i<n && j<n);
    		cout<<i+1<<" "<<j+1<<endl;
    		if(i==n-1 && j==n-1) break;
    		ll next_bit = (1LL << (i+j+1)) & k;
    		if(next_bit) { // then next i is even
    			if(i & 1) ++i;
    			else ++j;
    		} else {
    			if(i & 1) ++j;
    			else ++i;
    		}
    	}
    }



}