#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	map<int, int> val;

	int n;
	cin >> n;

	rep(_,0,n){
		int a,x;
		cin >> a >> x;
		val[a] = x;
	}

	int m;
	cin >> m;

	rep(_,0,m){
		int b, y;
		cin >> b >> y;

		if(!val.count(b)) val[b] = y;
		else if(val[b] < y) val[b] = y;
	}

	ll ans = 0;
	trav(pa, val) ans += pa.second;
	cout << ans << endl;

}