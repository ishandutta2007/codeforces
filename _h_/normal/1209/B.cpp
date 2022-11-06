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

	string s;
	cin >> s;
	vi a(n), b(n);
	rep(i,0,n) cin >> a[i] >> b[i];
	int T = 3 * 4 * 5 * 2 + 10;
	vector<vi> f(T, vi(n));
	rep(i,0,n) f[0][i] = s[i]-'0';
	rep(t,1,T) rep(i,0,n){
		if( (t-b[i])%a[i] == 0 && t >= b[i])
			f[t][i] = 1 - f[t-1][i];
		else
			f[t][i] = f[t-1][i];
	}
	int rek = 0;
	rep(t,0,T){
		int cur = 0;
		rep(i,0,n) cur += f[t][i];
		rek = max(rek, cur);
	}
	cout << rek << endl;
}