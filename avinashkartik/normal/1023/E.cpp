#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<lint, int>;

int query(int sx, int sy, int ex, int ey){
	printf("? %d %d %d %d\n", sx, sy, ex, ey);
	fflush(stdout);
	string s; cin >> s;
	if(s == "YES") return 1;
	return 0;
}

int main(){
	int n;
	cin >> n;
	int sx = 1, sy = 1;
	string l, r;
	while(sx + sy < n + 1){
		if(sx + 1 <= n && query(sx + 1, sy, n, n)){
			l.push_back('D');
			sx++;
		}
		else{
			l.push_back('R');
			sy++;
		}
	}
	sx = n, sy = n;
	while(sx + sy > n + 1){
		if(sy > 1 && query(1, 1, sx, sy - 1)){
			r.push_back('R');
			sy--;
		}
		else{
			r.push_back('D');
			sx--;
		}
	}
	reverse(r.begin(), r.end());
	l = l + r;
	printf("! %s\n", l.c_str());
}