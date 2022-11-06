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
	
	int n, m;
	cin >> n >> m;
	vector<string> ss(n);
	trav(s, ss) cin >> s;

	int xmn = n, xmx = 0;
	int ymn = m, ymx = 0;

	rep(i,0,n) rep(j,0,m) if(ss[i][j] == 'B'){
		xmn = min(xmn, i);
		xmx = max(xmx, i);
		ymn = min(ymn, j);
		ymx = max(ymx, j);
	}
	cout << 1+(xmn + xmx)/2 << ' ' << 1+(ymn+ymx)/2 << endl;
}