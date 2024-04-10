#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

typedef complex<ll> P;
typedef pair<P, ll> Q;

bool cross(P a, P b){
	return __int128(a.real()) * b.imag() < __int128(a.imag()) * b.real();
}

ll gcd(ll a, ll b){
	a = abs(a), b = abs(b);
	while(a){
		b %= a;
		swap(a, b);
	}
	return b;
}

Q get_point(){
	int s, p, g;
	cin >> s >> p >> g;
	return { {s, p}, s+p+g };
}

void reduce(P &p){
	ll d = gcd(p.real(), p.imag());
	if(d != 0) p /= d;
}

pair<ll, ll> to_pair(P a){
	return {a.real(), a.imag()};
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	Q ori = get_point();

	int n;
	cin >> n;

	auto p_comp = [](P a, P b){
		bool as = to_pair(a) < make_pair(0ll,0ll);
		bool bs = to_pair(b) < make_pair(0ll,0ll);
		if( as != bs ) return as < bs;
		return cross(a, b);
	};

	map< P, int, decltype(p_comp) > ms(p_comp);
	set< P, decltype(p_comp) > ss(p_comp);

	vector<P> ps;
	int ones = 0, twos = 0, ntr = 0;

	auto ntr_calc = [&](P a, bool strict){
		if(sz(ss) < 2) return false;
		auto jt = strict ? ss.upper_bound(a) : ss.lower_bound(a);
		if(jt == ss.end()) jt = ss.begin();
		auto it = prev(jt == ss.begin() ? ss.end() : jt);
		return cross(*jt, *it);
	};

	auto upd = [&](P a, int dif){
		if(a == P(0,0)){
			ones += dif;
		} else {
			int pr = ms[a],
			    nx = pr + dif;
			ms[a] = nx;
			if(pr == 0){
				if(ss.count(-a)) twos++;
				ntr -= ntr_calc(a, false);
				ss.insert(a);
				ntr += ntr_calc(a, true);
				ntr += ntr_calc(a, false);
			} else if(nx == 0){
				if(ss.count(-a)) twos--;
				ntr -= ntr_calc(a, true);
				ntr -= ntr_calc(a, false);
				ss.erase(a);
				ntr += ntr_calc(a, false);
			}
		}
	};

	rep(_,0,n){
		char c;
		cin >> c;
		if(c == 'A'){
			Q q = get_point();
			P p ( q.first * ori.second - 
			     ori.first * q.second );
			reduce(p);
			ps.push_back(p);
			upd(p, 1);	
		} else {
			int r;
			cin >> r;
			upd(ps[r-1], -1);
		}
		int ans = 0;
		if(!ntr && sz(ss) > 2) ans = 3;
		if(twos) ans = 2;
		if(ones) ans = 1;
		cout << ans << endl;
	}
}