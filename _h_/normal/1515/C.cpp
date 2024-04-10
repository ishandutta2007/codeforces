#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

void solve(){
	int n, m, x;
	cin >> n >> m >> x;

	priority_queue<pii> ls;
	rep(i,0,m) ls.push({0,i+1});

	vi ans;

	rep(_,0,n){
		int h;
		cin >> h;
		pii p = ls.top();
		ls.pop();
		ans.push_back(p.second);
		ls.push({p.first - h, p.second});
	}
	cout << "YES" << endl;
	trav(i, ans) cout << i << " ";
	cout << endl;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(_,0,n){
		solve();
	}
}