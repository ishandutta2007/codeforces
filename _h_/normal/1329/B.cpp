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

ll solve(int d, ll m){
	ll prod = 1;
	int t = 0;
	while((1<<t) <= d){
		int cur = min(d, (1<<(t+1))-1) - (1<<t) + 1;
		prod = prod * (cur+1) % m;
		t++;
	}
	return (prod + m - 1)%m;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(_,0,n){
		int d, m;
		cin >> d >> m;
		cout << solve(d,m) << endl;
	}
}