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

	ll x = 0, y = 0;

	rep(_,0,2*n){
		int a, b;
		cin >> a >> b;
		x += a, y += b;
	}
	assert(x%n == 0 && y%n == 0);

	cout << x/n << ' ' << y/n << endl;
}