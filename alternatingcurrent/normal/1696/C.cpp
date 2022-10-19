#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;

ll T;
ll n[2], m;
ll a[2][100100];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n[0] >> m;
		rep(i, n[0])
			cin >> a[0][i];
		cin >> n[1];
		rep(i, n[1])
			cin >> a[1][i];
		stack< pair<ll, ll> > stk[2];
		rep(tp, 2){
			rep(i, n[tp]){
				ll val = a[tp][i], cnt = 1;
				while(val % m == 0)
					val /= m, cnt *= m;
				if(!stk[tp].empty() && stk[tp].top().first == val)
					cnt += stk[tp].top().second, stk[tp].pop();
				stk[tp].push(make_pair(val, cnt));
			}
		}
		bool ok = (stk[0].size() == stk[1].size());
		while(!stk[0].empty() && !stk[1].empty()){
			ok &= stk[0].top() == stk[1].top();
			stk[0].pop(), stk[1].pop();
		}
		cout << (ok ? "Yes" : "No") << endl;
	}
	return 0;
}