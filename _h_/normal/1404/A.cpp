#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

void solve(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string cur(k, '?');
	rep(i,0,n) if(s[i] != '?'){
		int j = i % k;
		if(cur[j] == '?'){
			cur[j] = s[i];
		} else if(cur[j] != s[i]){
			cout << "NO" << endl;
			return;
		}
	}
	cout << (count(all(cur), '0')*2 > k || count(all(cur), '1')*2 > k ?
			"NO" : "YES") << endl;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(_,0,n) solve();
}