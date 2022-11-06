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
	
	string s;
	cin >> s;
	reverse(all(s));
	int n = sz(s);
	string mn(n,'.');
	mn[0] = s[0];
	rep(i,1,n) mn[i] = min(mn[i-1], s[i]);
	string t, u;
	for(int i = n-1; i>=0 || sz(t);){
		if(i>=0 && (t.empty() || t.back() > mn[i])){
			t.push_back(s[i]);
			--i;
		} else {
			u.push_back(t.back());
			t.pop_back();
		}
	}
	cout << u << endl;
}