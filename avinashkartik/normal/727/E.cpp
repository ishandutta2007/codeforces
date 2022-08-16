#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()           
 
typedef  long long             ll;
typedef  unsigned long long    ull;
typedef  long double           ld;
typedef  pair<ll,ull>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  3e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, k, q;
map <pll, ll> ct;
string s;

ll base = 1e9+7;
const ll hMOD = 1e9+123; 
ll pow1[N]; 
ull pow2[N]; 
ll pref1[N]; 
ull pref2[N]; 
 
void init_base(){
    pow1[0] = pow2[0] = 1;
    for(int i=1; i<N; i++) {
        pow1[i] = pow1[i-1] * base % hMOD;
        pow2[i] = pow2[i-1] * base;
    }
}
 
struct PolyHash { 
    PolyHash(const string& s){
        int n = s.size();
        pref1[0] = pref2[0] = 0;
        for (int i = 1; i <= n; i++) {
            pref1[i] = (pref1[i-1] + s[i] * pow1[i-1]) % hMOD;
            pref2[i] = pref2[i-1] + s[i] * pow2[i-1];
        }
    }
 
    inline pair<ll, ull> operator()(const int pos, const int len, const int mxPow = 0) const {
        ll hash1 = pref1[pos+len-1] - pref1[pos-1];
        ull hash2 = pref2[pos+len-1] - pref2[pos-1];
        if (hash1 < 0) hash1 += hMOD;
        if (mxPow != 0) {
            hash1 = hash1 * pow1[mxPow-(pos+len-1)] % hMOD;
            hash2 *= pow2[mxPow-(pos+len-1)];
        }
        return make_pair(hash1, hash2);
    }
};

void solve(){
	init_base();
	cin >> n >> k >> s;
	s = '#'+s+s;
	cin >> q;
	for(int i = 1; i <= q; i++){
		string t; cin >> t;
		PolyHash hash('#'+t);
		ct[hash(1,k,N)] = i;
	}
	PolyHash hash(s);
	for(int i = 1; i <= k; i++){
		vector <ll> v; set <ll> s;
		for(int j = i; j < n*k+i; j += k){
			pll val = hash(j,k,N);
			if(ct.find(val) != ct.end()) s.insert(ct[val]), v.pb(ct[val]);
		}
		if(s.size() == n){
			deb1("YES")
			debv(v)
			return;
		}
	}
	deb1("NO")
}

int main(){
	GODSPEED;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}