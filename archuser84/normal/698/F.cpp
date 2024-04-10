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

/// debug crap ///
template<class T>
ostream& operator<<(ostream& str, vector<T> vec){
	str << "(";
	if(vec.size()){
		Loop(i,0,vec.size()-1)
			str << vec[i] << ", ";
		str << vec.back();
	}
	str << ")";
	return str;
}
void _impl_dbg(){}
template<class T, class... U> void _impl_dbg(T x, U... y){
	cout << x << ' ';
	_impl_dbg(y...);
}
template<class... T> void _dbg(T... x){
	cout << "dbg: ";
	_impl_dbg(x...);
	cout << '\n';
}
template<class... T> void _vdbg(T... x){
	cout << "vdbg: ";
	_impl_dbg(x...);
	cout << '\n';
}
#if defined DBG || defined VRB
#define dbg(...) _dbg(__VA_ARGS__)
#else
#define dbg(...) NULL
#endif
#ifdef VRB
#define vdbg(...) _vdbg(__VA_ARGS__)
#else
#define vdbg(...) NULL
#endif
/// end of debug crap ///

const int N = 1000010;
int a[N];
int mp[2][N]; // map between primes > sq
int n, sq;

/// sieve crap ///
bitset<N> prm;
int cls[N]; // the class each number is in
int cnt[N]; // count of each class
int cntp[N]; // # of prime divisors of x
int big[N]; // biggest prime div of x
void sieve(){
	prm.set(); prm[0]=prm[1]=0;
	fill(cls+1,cls+N,1);
	for(int x=2; x <= n; ++x){
		if(!prm[x]) continue;
		if(2*x <= n)
			for(int y = x; y <= n; y += x)
				cls[y] *= x;
		for(int y = 2*x; y <= n; y += x)
			prm[y]=0;
		for(int y = x; y <= n; y += x){
			big[y]=x;
			++cntp[y];
		}
	}
	Loop(i,1,n+1) cnt[cls[i]]++;
}
/// end of sieve crap ///

const int mod = 1e9+7;
ll fct[N];
int unmap[N]; // # of unmapped which appear x times

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n; sq = sqrt(n);
	sieve();
	dbg("class:",vector<int>(cls+1,cls+1+n));
	Loop(i,0,n)
		cin >> a[i];
	Loop(i,0,n){ // checking if each number is in a compatible class and updating the mapping
		if(!a[i]) continue;
		if(cnt[cls[a[i]]] != cnt[cls[i+1]]) // incompatible
			Kill((dbg(a[i],"is of class",cls[a[i]],"but its index (",i+1,") is of",cls[i+1],"which are incompatible"), 0));
		int ba = big[cls[a[i]]], bi = big[cls[i+1]];
		if(ba > sq) // must update the mapping
		{
			if(n/ba != n/bi)
				Kill((dbg(ba,"must be mapped to",bi,"which are incompatible"),0));
			if(mp[0][bi] && mp[0][bi] != ba) Kill((dbg("contradiction in mapping:",bi,"must be mapped to both",ba,mp[0][ba]),0));
			if(mp[1][ba] && mp[1][ba] != bi) Kill((dbg("contradiction in mapping: both",bi,mp[1][ba],"must be mapped to",ba),0));
			mp[0][bi] = ba;
			mp[1][ba] = bi;
		}
	}
	dbg("map:",vector<int>(mp[0]+1,mp[0]+1+n));
	Loop(i,sq+1,n+1) // calcing unmapped
		if(2*i<=n && prm[i] && !mp[0][i]){
			unmap[n/i]++;
		}
	dbg("unmap:",vector<int>(unmap+1,unmap+1+n));
	dbg("pre-cnt:",vector<int>(cnt+1,cnt+1+n));
	Loop(i,0,n) // removing numbers from cnt
		cnt[cls[a[i]]]--;
	dbg("cnt:",vector<int>(cnt+1,cnt+1+n));

	fct[0] = 1; Loop(i,1,N) fct[i] = fct[i-1]*i % mod;

	ll ans = 1; // ans will be Pi unmap[i]! * Pi cnt[x]!
	Loop(x,1,n+1) ans = ans*fct[cnt[x]] % mod;
	Loop(x,1,n+1) ans = ans*fct[unmap[x]] % mod;
	cout << ans << '\n';
}