#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
typedef long long ll;
const ll INF=1e15+7;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll n, begin_pos=0, end_pos=0, begin_time=0, end_time=0, ans=0;
		cin >> n;
		pair<ll,ll>T[n+1];
		rep(i, n) cin >> T[i].first >> T[i].second;
		T[n].first=INF;
		rep(i, n) {
			if(T[i].first>=end_time) {
				begin_pos=end_pos;
				end_pos=T[i].second;
				begin_time=T[i].first;
				end_time=begin_time+abs(begin_pos-end_pos);
				if(end_time<=T[i+1].first) ++ans;
			} else if((begin_pos-end_pos)*(begin_pos-T[i].second)>=0 && abs(begin_pos-end_pos)>=abs(begin_pos-T[i].second)) {
				ll tap=abs(begin_pos-T[i].second)+begin_time;
				if(T[i].first<=tap && tap<=T[i+1].first) ++ans;
			}
		}
		cout << ans << '\n';
	}
}