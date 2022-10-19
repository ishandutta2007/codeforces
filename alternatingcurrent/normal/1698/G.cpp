#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;

string s;
ll F;
const ll B = 185400;
__gnu_pbds::cc_hash_table<ll, int> mp;

int main(){
	ios::sync_with_stdio(false);
	
	cin >> s;
	int st = 0;
	while(st < (int)s.size() && s[st] == '0') ++st;
	for(int i = st; i < (int)s.size(); ++i) F |= (ll)(s[i] - '0') << i;
	if(F == 0){
		cout << "-1\n";
		return 0;
	}
	
	ll nval = 1;
	if((nval ^ F) < nval)
		nval ^= F;
	rep(i, B){
		mp[nval] = i; // pB-q, find big q
		nval <<= 1;
		if((nval ^ F) < nval)
			nval ^= F;
	}
	
	ll P = nval;
	ll ans = -1;
	for(int i = 1; i <= B; ++i){
		if(mp.find(nval) != mp.end()){
			ans = i * B - mp[nval];
			break; // break;
		}
		
		ll tmp = 0;
		for(int j = 35; j >= 0; --j){
			tmp <<= 1;
			if(nval & (1ll << j))
				tmp ^= P;
			if((tmp ^ F) < tmp)
				tmp ^= F;
		}
		nval = tmp;
	}
	
	if(ans < 0)
		cout << "-1\n";
	else {
		cout << st+1 << " " << ans+st+1 << endl;
	}
	
	return 0;
}