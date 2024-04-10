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

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	rep(m,'0','9'+1){
		string ans(n, '0');
		char prev = m;
		rrep(i,0,n) if(ans[i]=='0' && s[i] <= prev){
			prev = s[i];
			ans[i] = '1';
		}
		prev = m;
		rep(i,0,n) if(ans[i]=='0' && s[i] >= prev){
			prev = s[i];
			ans[i] = '2';
		}
		if(count(all(ans), '0') == 0){
			cout << ans << endl;
			return;
		}
	}
	cout << "-" << endl;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	rep(_,0,n) solve();
}