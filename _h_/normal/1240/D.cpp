// written by aitch
// on 2019 10/24 at 11:58:39
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

ll solve(){
	int n;
	cin >> n;

	vi a(n);
	trav(x, a) cin >> x;

	vi num(n+1);
	vector<map<int,int>> fs(n+1);

	ll ans = 0;

	rrep(i,0,n){
		int v = a[i];
		int j = n;
		if(fs[i+1].count(v)){
			j = fs[i+1][v];
			num[i] = 1 + num[j+1];
			ans += num[i];
			swap(fs[i], fs[j+1]);
		}
		fs[i][v] = i;
	}
	return ans;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	rep(_,0,n) cout << solve() << endl;
}