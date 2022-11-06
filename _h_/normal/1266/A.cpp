// written by aitch
// on 2019 12/17 at 16:05:00
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

	rep(_,0,n){
		string s;
		cin >> s;
		int mod3 = 0;
		trav(c, s) mod3 = (mod3 + c-'0')%3;
		bool z = count(all(s), '0');
		int ev = 0;
		trav(c, s) ev += (c-'0')%2 == 0;
		if(mod3 || !z || ev < 2) cout << "cyan" << endl;
		else cout << "red" << endl;
	}
}