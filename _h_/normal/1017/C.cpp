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

	int a = 1;
	while(a*a < n) ++a;
	int ix = 1;
	vi ans;
	while(sz(ans) < n){
		int d = min(n - sz(ans), a);
		int s = ix+d-1;
		ix = s+1;
		rep(i,0,d) ans.push_back(s-i);
	}
	trav(x, ans) cout << x << ' ';
	cout << endl;
}