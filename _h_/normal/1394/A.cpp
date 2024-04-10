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

	int n, d, m;
	cin >> n >> d >> m;

	vector<ll> lo, hi;
	rep(_,0,n){
		int a;
		cin >> a;
		if(a <= m) lo.push_back(a);
		else hi.push_back(a);
	}
	sort(all(lo));
	sort(all(hi));
	reverse(all(hi));

	vector<ll> lop(sz(lo)+1), hip(sz(hi)+1);
	rep(i,0,sz(lo)) lop[i+1] = lop[i] + lo[i];
	rep(i,0,sz(hi)) hip[i+1] = hip[i] + hi[i];

	auto calc = [&](int num){
		if(num > sz(hi) || num * (d+1) > n + d) return (ll)-1;
		int res = num * (d+1) - d;
		return hip[num] + lop.back()
			- lop[max(0, res - sz(hi))];
	};

	int num = 0;
	while(calc(num+1) > calc(num)) ++num;
	cout << calc(num) << endl;
}