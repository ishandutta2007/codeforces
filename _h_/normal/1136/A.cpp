// written by aitch
// on 2019 09/20 at 22:57:10
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

	vi l(n), r(n);
	rep(i,0,n) cin >> l[i] >> r[i];
	int k;
	cin >> k;
	
	int ans = 0;
	rep(i,0,n) if(r[i] >= k) ans++;
	cout << ans << endl;
}