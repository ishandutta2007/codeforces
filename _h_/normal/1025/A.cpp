#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

bool solve(){
	int n;
	cin >> n;
	if(n == 1 || n > 26) return true;
	string s;
	cin >> s;
	sort(all(s));
	rep(i,1,n) if(s[i] == s[i-1]) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cout << (solve() ? "Yes" : "No") << endl;
}