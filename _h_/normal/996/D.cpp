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

	vi a(2*n);
	trav(x, a) cin >> x;

	int ans = 0;
	rep(i,0,n){
		int j;
		rep(k,2*i+1,2*n) if(a[k]==a[2*i]) j = k;
		ans += j - 2*i-1;
		rrep(k,2*i+1,j) swap(a[k], a[k+1]);
	}
	cout << ans << endl;
}