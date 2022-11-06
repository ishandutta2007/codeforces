// written by aitch
// on 2019 12/17 at 16:05:00
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

	rep(_,0,n){
		ll x;
		cin >> x;
		ll q = max(0ll, x/14-1);
		x -= q * 14;
		if(x < 15 || x > 20) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}