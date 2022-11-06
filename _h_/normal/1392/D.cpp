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

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(_,0,n){
		int m;	
		cin >> m;
		string s;
		cin >> s;
		if(count(all(s), s[0]) == m){
			cout << (m+2)/3 << endl;	
			continue;
		}
		s = s;
		int ans = 0;
		rep(i,0,m) if(s[(i+1)%m] != s[i]){
			int j = i+2;
			while(s[j%m] != s[i]) ++j;
			ans += (j-i-1)/3;
		}
		cout << ans << endl;
	}
}