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
	vi as(n);
	trav(x, as) cin >> x;
	int d = 0, s = 0;
	reverse(all(as));
	trav(x, as){
		int d2 = max(d, x+s);
		int s2 = x+s+d - d2;
		d = d2;
		s = s2;
	}
	cout << s << ' ' << d << endl;
}