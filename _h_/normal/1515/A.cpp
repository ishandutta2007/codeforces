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
	int n, x;
	cin >> n >> x;
	vi ws(n);
	trav(w,ws) cin >> w;
	int cur = 0;
	rep(i,0,n){
		cur += ws[i];
		if(cur == x){
			if(i == n-1){
				cout << "NO" << endl;
				return;
			} else {
				swap(ws[i], ws[i+1]);
				break;
			}
		}
	}
	cout << "YES" << endl;
	trav(x, ws) cout << x << " ";
	cout << endl;
	return;
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