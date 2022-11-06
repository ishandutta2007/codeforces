// written by aitch
// on 2019 12/05 at 14:35:01
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

void fail(){
	cout << "NO" << endl;
	exit(0);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int a,b,c,d;
	cin >> a >> b >> c >> d;
	string s;
	if(a+c == b+d){
		if(a > b || d > c) fail();
		rep(_,0,a) s += "01";
		rep(_,0,d) s += "23";
		rep(_,0,b-a) s += "21";
		cout << "YES" << endl;
		trav(c, s) cout << c << " ";
		cout << endl;
		return 0;
	} else if(a+c == b+d+1){
		if(c == 0){
			if(d) fail();
			rep(_,0,b) s += "01";
			s += "0";
			cout << "YES" << endl;
			trav(c, s) cout << c << " ";
			cout << endl;
			return 0;
		} else {
			--c;
			if(a > b || d > c) fail();
			string s;
			rep(_,0,a) s += "01";
			rep(_,0,d) s += "23";
			rep(_,0,b-a) s += "21";
			s += "2";
			cout << "YES" << endl;
			trav(c, s) cout << c << " ";
			cout << endl;
			return 0;
		}
	} else if(b+d == a+c+1){
		if(b == 0){
			if(a) fail();
			rep(_,0,c) s += "32";
			s += "3";
			cout << "YES" << endl;
			trav(c, s) cout << c << " ";
			cout << endl;
			return 0;
		} else {
			--b;
			if(a > b || d > c) fail();
			string s;
			rep(_,0,d) s += "32";
			rep(_,0,a) s += "10";
			rep(_,0,b-a) s += "12";
			s += "1";
			cout << "YES" << endl;
			trav(c, s) cout << c << " ";
			cout << endl;
			return 0;
		}
	} else {
		fail();
	}
}