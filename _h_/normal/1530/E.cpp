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

string solve(){
	string s;
	cin >> s;
	if(count(all(s), s[0]) == sz(s)){
		return s;
	}
	sort(all(s));
	rep(i,0,sz(s)){
		if( (i == 0 || s[i-1] != s[i]) && (i+1 == sz(s) || s[i+1] != s[i]) ){
			swap(s[0], s[i]);
			sort(s.begin()+1, s.end());
			return s;
		}
	}

	if(2 <= count(all(s), s[0]) && count(all(s), s[0])*2 <= sz(s) + 2){
		string t;
		trav(c, s) if(c != s[0]) t.push_back(c);
		int lft = count(all(s), s[0]) - 2;
		int tix = 0;
		rep(i,2,sz(s)){
			if(lft > 0 && s[i-1] != s[0]){
				s[i] = s[0];
				--lft;
			} else {
				s[i] = t[tix++];	
			}
		}
		return s;
	} else {
		int i = 0;
		while(s[i] == s[0]) ++i;
		swap(s[1], s[i]);

		if(count(all(s), s[0]) + count(all(s), s[1]) == sz(s)){
			sort(s.begin() + 2, s.end());
			reverse(s.begin()+2, s.end());
			return s;
		} else {
			int j = i+1;
			while(s[j] == s[1]) ++j;
			swap(s[i+1], s[j]);
			sort(s.begin() + i+2, s.end());
			return s;
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(_,0,n){
		cout << solve() << endl;
	}
}