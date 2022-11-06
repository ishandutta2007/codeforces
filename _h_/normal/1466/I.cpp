#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define sz(v) int(v.size())
using namespace std;

string inf, zero;

string add(string x, string y, int init){
	string res(sz(x), '?');
	int todo = init;
	rrep(i,0,sz(x)){
		todo += x[i] + y[i] - 2 * '0';
		res[i] = todo % 2 + '0';
		todo /= 2;
	}
	if(todo) return inf;
	return res;
}

int main(){
	int n, b;
	cin >> n >> b;
	inf = string(b, '1');
	zero = string(b, '0');

	vector<string> fibs = {zero, zero}; // fibonacci numbers minus one
	while(fibs.back() < inf)
		fibs.push_back(add(fibs.back(), fibs[sz(fibs)-2], 1));
	int todo = sz(fibs)-1;
	deque<pair<int, bool>> ls;
	rep(i,0,n) ls.push_back({i+1, true});
	string lb = zero; // current lower bound
	while(!ls.empty()){
		string ans;
		if(add(lb, fibs[todo], 0) == inf) ans = "no";
		else { cout << ls.back().first << " " << add(lb, fibs[max(0, todo)], 0) << endl;
		       cin >> ans; } 
		if(ans == "yes"){
			lb = add(lb, fibs[todo], 1);
			while(!ls.empty() && ls[0].second){
				ls.pop_front();
				todo += 2;
			}
			if(ls.empty()) break;
			ls[0].second = true;
		} else {
			ls.push_front({ls.back().first, false});
			ls.pop_back();
		}
		if(--todo <= 0){
			todo += ls[0].second ? 2 : 1;
			ls.pop_front();
		}
	}
	cout << 0 << " " << lb << endl;
}