#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define rep(i,a,b) for(int (i)=(int)(a); (i) < (int)(b); ++(i))
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> pll;
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	ll l,r;
	cin >> n >> m >> l >> r;
	--n;
	if(m < n){
		cout << "No" << endl;
		return 0;
	}
	vector<pair<pll,int> >val(n);
	rep(i,0,n){
		ll lny,rny;
		cin >> lny >> rny;
		val[i] = mp(mp(rny - l, lny - r),i);
		r = rny, l = lny;
	}
	sort(val.begin(), val.end());
	set<pll> ms;
	rep(i,0,m){
		ll a;
		cin >> a;
		ms.insert(mp(a,i+1));
	}
	vector<int> svar(n);
	for(auto pd : val){
		auto p = pd.first;
		auto it = ms.lower_bound(mp(p.second,0));
		if(it == ms.end() || it->first > p.first){
			cout << "No" << endl;
			return 0;
		}
		svar[pd.second] = it->second;
		ms.erase(it);
	}
	cout << "Yes" << endl;
	for(auto i : svar)
		cout << i << ' ';
	cout << endl;
}