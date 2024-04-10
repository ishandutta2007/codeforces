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
	cout.precision(8);

	int n, r;
	cin >> n >> r;

	ll sum = 0;

	vi c(1<<n);

	trav(x, c) cin >> x;

	trav(x, c) sum += x;

	cout << sum*1./(1<<n) << endl;

	rep(_,0,r){
		int z,g;
		cin >> z >> g;
		sum += g - c[z];
		c[z] = g;
		cout << sum*1./(1<<n) << endl;
	}
}