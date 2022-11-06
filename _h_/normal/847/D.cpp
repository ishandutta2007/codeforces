#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,t;
	cin >> n >> t;
	vi ts(n);
	trav(x,ts) cin >> x;
	int dif = max(1, t-n);
	trav(x, ts) x = max(0, x-dif);
	t -= dif;
	vi ra(t+1);
	rep(i,0,t){
		int l = max(0, ts[i]-i), r = t-i;
		if(l >= r) continue;
		ra[l]++;
		ra[r]--;
	}
	int ans = 0;
	int cur = 0;
	rep(i,0,t){
		cur += ra[i];
		ans = max(ans, cur);
	}
	cout << ans << endl;
}