#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define trav(x, v) for(auto &x : v)
#define all(v) v.begin(), v.end()
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<vi> vvi;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	vi as(n);
	trav(x, as) cin >> x;

	int mn = 51;
	trav(x, as) mn = min(mn, x);
	int cnt = count(all(as), mn);
	if(cnt*2 > n) cout << "Bob" << endl;
	else cout << "Alice" << endl;
}