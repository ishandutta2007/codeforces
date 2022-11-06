// written by aitch
// on 2019 10/20 at 16:11:01
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

const ll md = 1e9+7;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	vector<ll> fib(1e5+1);
	fib[0] = fib[1] = 1;
	rep(i,2,1e5+1)
		fib[i] = (fib[i-1] + fib[i-2])%md;

	int n, m;
	cin >> n >> m;

	ll ans = fib[n] + fib[m] + md - 1;
	ans = ans * 2 % md;

	cout << ans << endl;
}