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

	string s;
	cin >> s;

	int ans = 0;
	int n = sz(s);

	rep(i,0,n) rep(j,i+1,n+1){
		rep(k,i,j) if(s[k] != s[i+j-1-k]){
			ans = max(ans, j-i);
		}
	}

	cout << ans << endl;
}