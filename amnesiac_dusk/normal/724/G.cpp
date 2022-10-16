//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
#else
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=4e18;
const int infi=1e9;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(ll a, ll b) {
	int res=1;
	a%=mod;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

const int BITS = 60;

template<typename T>
struct xor_basis {
// A list of basis values sorted in decreasing order, where each value has a unique highest bit.
// We use a static array instead of a vector for better performance.
    T basis[BITS];
    int n = 0;
    T min_value(T start) const {
        for (int i = 0; i < n; i++)
            start = min(start, start ^ basis[i]);

        return start;
    }

    T max_value(T start = 0) const {
        for (int i = 0; i < n; i++)
            start = max(start, start ^ basis[i]);

        return start;
    }

    bool add(T x) {
        if (n == BITS)
            return false;

        x = min_value(x);

        if (x == 0)
            return false;

        basis[n++] = x;

        // Insertion sort.
        for (int k = n - 1; k > 0 && basis[k] > basis[k - 1]; k--)
            swap(basis[k], basis[k - 1]);

        return true;
    }

    void merge(const xor_basis<T> &other) {
        for (int i = 0; i < other.n && n < BITS; i++)
            add(other.basis[i]);
    }

    void merge(const xor_basis<T> &a, const xor_basis<T> &b) {
        *this = a;
        merge(b);
    }
};

const int N=1e5+5;
xor_basis<int> xorian[N];
int dsu[N],xo[N];
int fpar(int i) {
	if(dsu[i]<0)
		return i;
	int pare=dsu[i];
	dsu[i]=fpar(dsu[i]);
	xo[i]^=xo[pare];
	return dsu[i];
}
void merge(int u, int v,int w) {
	int ori=u,orj=v;
	if((u=fpar(u))!=(v=fpar(v))) {
		if(dsu[u]>dsu[v])
			swap(u,v);
		dsu[u]+=dsu[v];
		dsu[v]=u;
		xorian[u].merge(xorian[v]);
		xo[v]=w^xo[ori]^xo[orj];
	} else {
		xorian[u].add(w^xo[ori]^xo[orj]);
	}
}
vi coms[N];
void solve() {
	int n,m;
	memset(dsu,-1,sizeof(dsu));
	cin>>n>>m;
	fr(i,1,m) {
		int u,v,w;
		cin>>u>>v>>w;
		merge(u,v,w);
	}
	fr(i,1,n) {
		coms[fpar(i)].pb(i);
	}
	int ans=0;
	fr(i,1,n) {
		if(!coms[i].empty()) {
			trace(i);
			int present=0;
			fr(j,0,xorian[i].n-1) {
				present|=xorian[i].basis[j];
			}
			fr(j,0,59) {
				int zero=0,one=0;
				for(int k:coms[i]) {
					if(xo[k]&(1LL<<j))
						one++;
					else
						zero++;
				}
				if(xorian[i].n) {
					int numlin=((1LL<<(xorian[i].n-1))%mod*((1LL<<j)%mod))%mod;
					ans=(ans+((one*zero)%mod)*numlin)%mod;
					if(present&(1LL<<j)) {
						ans=(ans+numlin*(((zero*(zero-1)+one*(one-1))/2)%mod))%mod;
					} else {
						ans=(ans+((one*zero)%mod)*numlin)%mod;
					}
				} else {
					int numlin=(1LL<<j)%mod;
					ans=(ans+((one*zero)%mod)*numlin)%mod;
				}
				trace(one,zero);
			}
		}
	}
	cout<<ans<<endl;
}


signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	fflush(stdout);
	cerr<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}