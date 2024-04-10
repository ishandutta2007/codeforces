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

const int N = 3e5+10;
int n;
vector<int> cmp;
vector<pii> A[N];
int l[N], r[N];
int ans[N];
int m;

void Do(int v){
	for(;;){
		while(A[v].size() && ans[A[v].back().second]) A[v].pop_back();
		if(A[v].empty()) break;
		auto [u, e] = A[v].back();
		ans[e] = 1+(v>u);
		v=u;
	}
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n; m=n;
	Loop(i,0,n){
		cin >> l[i] >> r[i]; --l[i];
		cmp.push_back(l[i]);
		cmp.push_back(r[i]);
	}
	sort(cmp.begin(), cmp.end());
	cmp.resize(unique(cmp.begin(), cmp.end()) - cmp.begin());
	Loop(i,0,n){
		l[i] = lower_bound(cmp.begin(), cmp.end(), l[i]) - cmp.begin();
		r[i] = lower_bound(cmp.begin(), cmp.end(), r[i]) - cmp.begin();
		A[l[i]].emplace_back(r[i],i);
		A[r[i]].emplace_back(l[i],i);
	}
	int odd=-1;
	Loop(i,0,cmp.size()){
		if(A[i].size()&1){
			if(odd==-1)odd=i;
			else {
				A[odd].emplace_back(i,m);
				A[i].emplace_back(odd,m);
				++m;
				odd=-1;
			}
		}
	}
	Loop(i,0,cmp.size()) Do(i);
	Loop(i,0,n)
		cout << ans[i]-1 << ' ';
	cout << '\n';
}