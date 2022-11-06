// written by _h_
// on 2020 01/04 at 13:05:01
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

	int n, m;
	cin >> n >> m;
	vector<string> s(n), t(m);
	trav(x, s) cin >> x;
	trav(x, t) cin >> x;
	int q;
	cin >> q;
	rep(_,0,q){
		int y;
		cin >> y;
		int i = (y-1) % n, j = (y-1) % m;
		cout << s[i] << t[j] << endl;
	}
}