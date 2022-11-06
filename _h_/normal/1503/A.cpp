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
	string s;
	cin >> n >> s;
	string a(n, '?'), b(n, '?');
	if(count(all(s), '0') % 2 || s[0] == '0' || s[n-1] == '0'){
		cout << "NO" << endl;
		return;
	}
	int tot = count(all(s),'1');
	int ix = 0, jx = 0;
	rep(i,0,n){
		if(s[i] == '1'){
			a[i] = b[i] = (ix*2 >= tot) ? ')' : '(';
			++ix;
		} else {
			a[i] = '(';
			b[i] = ')';
			if(jx % 2){
				swap(a[i], b[i]);
			}
			++jx;
		}
	}
	cout << "YES" << endl << a << endl << b << endl;
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