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

void fail(){
	cout << "NO" << endl;
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	string ans;

	set<pii> vis;

	function<void(int,int)> rek = [&](int i, int cur){
		if(!vis.insert({i,cur}).second) return;
		if(i==n){
			if(abs(cur) == k){
				cout << ans << endl;
				exit(0);
			} else return;
		}
		if(abs(cur) == k) return;
		string t;
		if(s[i] != '?') t.push_back(s[i]);
		else t = "WLD";
		trav(c, t){
			ans.push_back(c);
			rek(i+1,cur+(c=='W')-(c=='L'));
			ans.pop_back();
		}
	};
	rek(0,0);
	cout << "NO" << endl;
}