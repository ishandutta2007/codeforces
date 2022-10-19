#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
int n;
map< pair<int, int>, int > mp;
int l[100100], r[100100], c[100100];
int lb, ub;
int lbc, ubc;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		mp.clear();
		lb = 0x3f3f3f3f, ub = -1;
		rep(i, n){
			cin >> l[i] >> r[i] >> c[i];
			if(!(mp.count(make_pair(l[i], r[i])) && c[mp[make_pair(l[i], r[i])]] < c[i]))
				mp[make_pair(l[i], r[i])] = i;
			if(l[i] < lb){
				lb = l[i];
				lbc = c[i];
			} else if(l[i] == lb){
				lbc = min(lbc, c[i]);
			}
			if(r[i] > ub){
				ub = r[i];
				ubc = c[i];
			} else if(r[i] == ub){
				ubc = min(ubc, c[i]);
			}
			int ans = lbc + ubc;
			if(mp.count(make_pair(lb, ub)))
				ans = min(ans, c[mp[make_pair(lb, ub)]]);
			cout << ans << endl;
		}
	}
	return 0;
}