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

	int y, b, r;
	cin >> y >> b >> r;

	int m = 100;
	m = min(m, y);
	m = min(m, b-1);
	m = min(m, r-2);

	int ans = 3*m + 1 + 2;

	cout << ans << endl;
}