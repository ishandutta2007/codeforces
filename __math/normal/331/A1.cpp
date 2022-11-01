#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>

using namespace std;
const int MOD = 1000000007; // check!!!
//const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

ll a[3*ten(5)];
ll sa[3*ten(5) + 1];
ll sb[3*ten(5) + 1];

ll sum(int l,int r){
	return sa[r] - sa[l];
}

ll minus_sum(int l,int r){
	return sb[r] - sb[l];
}

int main(){
	int n;
	cin>>n;
	FOR(i,n) cin>>a[i];

	FOR(i,n) sa[i+1] = sa[i] + a[i];
	FOR(i,n) sb[i+1] = sb[i] + min(0LL,a[i]);

	map<ll,vector<int> > mp;
	FOR(i,n){
		mp[a[i]].push_back(i);
	}

	ll max_key;
	ll current_val = -(1LL << 60);

	for(map<ll,vector<int> >::iterator it = mp.begin(); it != mp.end(); ++it){
		if(it->second.size() < 2) continue;
		int l = it->second[0];
		int r = it->second.back() + 1;

		ll l1 = sum(l,r);
		ll l2 = minus_sum(l+1,r-1);

		ll tmp = l1 - l2;
		if(current_val < tmp){
			current_val = tmp;
			max_key = it->first;
		}
	}

	vector<int> ans;
	int al = mp[max_key][0];
	int ar = mp[max_key].back() + 1;
	FOR(i,n){
		if(i < al || i >= ar) ans.push_back(i);
		if(al < i && i+1 < ar && a[i] < 0) ans.push_back(i);
	}

	cout << current_val << " " << sz(ans) << endl;
	FOR(i,sz(ans)){
		if(i != 0) cout << " ";
		cout << ans[i] + 1;
	}
	cout << endl;

	return 0;
}