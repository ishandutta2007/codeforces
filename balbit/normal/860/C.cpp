#include <bits/stdc++.h>
#define int ll
using namespace std;
#define ll long long
#define y1 zck_is_king
#define pii pair<ll, ll>
#define ull unsigned ll
#define f first
#define s second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define REP(i,n) for (int i = 0; i<n; ++i)
#define RREP(i,n) for (int i = n-1; i>=0; --i)
#define REP1(i,n) for (int i = 1; i<=n; ++i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"#%d (%s) = ",__LINE__,#__VA_ARGS__),_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif

const int iinf = 1e9+10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9+7 ;


void GG(){cout<<"0\n"; exit(0);}

ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}

ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b,mo) % mo;
}

const int maxn = 1e5+5;

int n; 

int parse(string s) {
	for (char c : s) {
		if (c < '0' || c > '9') return -1;
	}
	if (s[0] == '0') return -1;
	ll tmp = stoll(s);
	if (tmp >= 1 && tmp <= n) return tmp;
	return -1;
}

signed main(){
    IOS();

    set<int> f0, f1; // free in sets one and two
    vector<string> alien0, alien1;

    cin>>n;
    int m = 0; // number of regular tests (to be placed later);

    vector<pii> stuff;

    // 1: examples, 0: regular tests

    REP(i,n) {
    	string s; cin>>s;
    	bool tp; cin>>tp;
    	m += tp==0;
    	int get = parse(s);
    	if (get == -1) {
    		(tp?alien1:alien0).pb(s);
    	}
    	else{
    		stuff.pb({get, tp});
    	}
    }

    n = n-m;
    bug(n,m);

    REP1(i,n) f1.insert(i);
    REP1(i,m) f0.insert(i+n);

    vector<int> chg0, chg1;

    for (pii p : stuff) {
    	if (p.f <= n) {
    		// examples; 1
    		f1.erase(p.f);
    		if (p.s != 1) {
    			chg0.pb(p.f);
    		}
    	}else{
    		f0.erase(p.f);
    		if (p.s != 0) {
    			chg1.pb(p.f);
    		}
    	}
    }

    vector<pair<string, string> > re;

    while (SZ(chg0) || SZ(chg1)) {
    	if (SZ(chg0) && SZ(f0)) {
    		int ya = chg0.back(); chg0.pop_back();
    		f1.insert(ya);
    		int take = *f0.begin(); f0.erase(take);
    		re.pb({to_string(ya), to_string(take)});
    	}else if (SZ(chg1) && SZ(f1)) {
    		int ya = chg1.back(); chg1.pop_back();
    		f0.insert(ya);
    		int take = *f1.begin(); f1.erase(take);
    		re.pb({to_string(ya), to_string(take)});
    	}else{
    		assert(SZ(chg0));
    		int sac = chg0.back(); chg0.pop_back();
    		f1.insert(sac); 
    		re.pb({to_string(sac), "b91iqk"});
    		alien0.pb("b91iqk");
    	}
    }

    while (SZ(alien0)) {
    	string ya = alien0.back(); alien0.pop_back();
    	int take = *f0.begin(); f0.erase(take);
    	re.pb({(ya), to_string(take)});
    }

    while (SZ(alien1)) {
    	string ya = alien1.back(); alien1.pop_back();
    	int take = *f1.begin(); f1.erase(take);
    	re.pb({(ya), to_string(take)});
    }

    cout<<SZ(re)<<endl;
    for (auto x : re) {
    	cout<<"move "<<x.f<<' '<<x.s<<endl;
    }


}