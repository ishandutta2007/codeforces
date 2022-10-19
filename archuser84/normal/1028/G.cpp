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

namespace dbgcrap{
	template<class T>
	ostream& operator<<(ostream& str, vector<T> vec){
		str << "[";
		if(vec.size()){
			Loop(i,0,vec.size()-1)
				str << vec[i] << ", ";
			str << vec.back();
		}
		str << "]";
		return str;
	}
	template<class T, class U>
	ostream& operator<<(ostream& str, pair<T,U> p){
		return str << "(" << p.first << ", " << p.second << ")";
	}
	void _impl_dbg(){}
	template<class T, class... U> void _impl_dbg(T x, U... y){
		cout << x << ' ';
		_impl_dbg(y...);
	}
	template<class... T> int _dbg(T... x){
		cout << "dbg: ";
		_impl_dbg(x...);
		cout << endl;
		return 0;
	}
#ifdef DBG
#define dbg(...) dbgcrap::_dbg(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
}

#define int ll

const ll M = 10004205361450474LL;

int Do(vector<ll>& v){
	const ll ans = 1234546;
	//assert(is_sorted(v.begin(), v.end());
	auto it = lower_bound(v.begin(), v.end(), ans);
	if(it != v.end() && *it == ans) return -1;
	return it-v.begin();
}

#include <cassert>

int query(const vector<ll>& v){
	int r = v.size();
	while(r && v[r-1] > M) --r;
	if(!r) return 0;
	stringstream s;
	s << r << ' ';
	Loop(i,0,r)
		s << v[i] << ' ';
	cout << s.str() << endl;
	int ans;
	cin >> ans;
	//int ans = Do(v);
	if(ans < 0) {
		//cout << clock() << ' ' << ans << '\n';
		exit(0);
	}
	return ans;
}

vector<ll> v;

void bin(ll l, ll r, ll base)
{
	while(r>1){
		v.clear();
		r /= base;
		for(ll i=1; i < base; ++i)
			v.push_back(l+r*i);
		l += query(v)*r;
	}
}

signed main()
{
	if(query({204761410474ll}) == 0) {
		if(query({2046}) == 0){
			if(query({6}) == 0) {
				if(query({2}) == 0) query({1});
				query({3,4,5});
			} else {
				v.clear(); Loop(i,4,11) v.push_back((1<<i)-2);
				int x = query(v);
				int l = x==0?7:v[x-1]+1;
				int r = x==v.size()?2046:v[x];
				v.clear();
				Loop(i,l,r)
					v.push_back(i);
				query(v);
			}
		} else {
			v = {20468427};
			Loop(i,0,2046) v.push_back(v.back() + 100020001);
			int x = query(v);
			if(x==0){
				v = {4094, 8190, 16382};
				Loop(i,0,2044) v.push_back(v.back() + 10001);
				int x = query(v);
				int l = x==0?2047:v[x-1]+1;
				int r = x==v.size()?20470236:v[x];
				v.clear();
				Loop(i,l,r)
					v.push_back(i);
				query(v);
			} else {
				bin(v[x-1], 100020001, 10001);
			}
		}
	}
	bin(204761410474ll, 10004000600040001ll, 10001);
}