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

	int n;
	cin >> n;

	vi a(n);
	trav(x, a) cin >> x;

	bool foo = false;
	rep(msk, 0, (1<<n)){
		int tot = 0;
		rep(i,0,n) tot += a[i] * ((msk&(1<<i)) ? 1 : -1);
		if(tot%360 == 0) foo = true;
	}
	cout << (foo ? "YES" : "NO") << endl;
}