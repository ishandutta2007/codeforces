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
	
	int n;
	cin >> n;

	vi x(n), y(n);

	trav(a, x) cin >> a;
	trav(a, y) cin >> a;

	ll dif = 0;
	trav(a, x) dif += a;
	trav(a, y) dif -= a;

	cout << (dif>=0 ? "Yes" : "No") << endl;
}