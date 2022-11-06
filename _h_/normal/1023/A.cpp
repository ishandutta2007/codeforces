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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	if(m < n-1){
		cout << "NO" << endl;
		return 0;
	}
	string s, t;
	cin >> s >> t;

	int p = -1;
	rep(i,0,n) if(s[i] == '*') p = i;
	
	if(p==-1){
		cout << (s == t  ? "YES" : "NO") << endl;
		return 0;
	}

	int l = n-p-1;

	if(s.substr(0, p) == t.substr(0,p) &&
	s.substr(n-l, l) == t.substr(m-l,l))
		cout << "YES" << endl;
	else cout << "NO" << endl;
}