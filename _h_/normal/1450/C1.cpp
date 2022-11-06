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
	int n;
	cin >> n;
	vector<string> ss(n);
	trav(x, ss) cin >> x;
	vi cnt(3);
	rep(i,0,n) rep(j,0,n) if(ss[i][j] == 'X') ++cnt[(i+j)%3];
	int k = 0;
	trav(x, cnt) k += x;
	rep(t,0,3) if(cnt[t] * 3 <= k){
		rep(i,0,n) rep(j,0,n) if(ss[i][j] == 'X' && (i+j)%3 == t){
			ss[i][j] = 'O';
		}
		break;
	}
	trav(s, ss) cout << s << endl;
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