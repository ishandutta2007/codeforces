#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	vi cnt(20);

	rep(_,0,n){
		int a;
		cin >> a;
		rep(t,0,20) if(a & (1<<t)) ++cnt[t];
	}

	ll ans = 0;

	rep(i,0,n){
		int num = 0;
		rep(t,0,20) if(cnt[t] > i) num += 1<<t;
		ans += ll(num) * num;
	}

	cout << ans << endl;
}