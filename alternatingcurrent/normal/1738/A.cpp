#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;

int t;
int n;
vector<ll> v[2];

int main(){
	ios::sync_with_stdio(false);
	
	cin >> t;
	while(t--){
		cin >> n;
		
		static int tp[100100], b[100100];
		rep(i, n)
			cin >> tp[i];
		rep(i, n)
			cin >> b[i];
		
		v[0].clear(), v[1].clear();
		
		ll sum = 0;
		rep(i, n){
			v[tp[i]].push_back(b[i]);
			sum += b[i];
		}
		sum <<= 1;
		
		if((int)v[0].size() == (int)v[1].size()){
			ll mn = v[0][0];
			rep(i, (int)v[0].size())
				mn = min(mn, v[0][i]);
			rep(i, (int)v[1].size())
				mn = min(mn, v[1][i]);
			cout << sum - mn << endl;
		} else {
			if((int)v[0].size() > (int)v[1].size())
				swap(v[0], v[1]);
			sort(v[1].begin(), v[1].end());
			
			for(int i = 0; i < (int)v[1].size() - (int)v[0].size(); ++i)
				sum -= v[1][i];
			cout << sum << endl;
		}
	}
	
	return 0;
}