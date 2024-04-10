#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
const int LIM=1e5+7, MOD=1e9+7;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		bool ans=false;
		int x=0, y=0;
		for(auto i : s) {
			if(i=='U') ++y;
			if(i=='D') --y;
			if(i=='R') ++x;
			if(i=='L') --x;
			int x2=0, y2=0;
			if(x==0 && y==0) continue;
			for(auto j : s) {
				if(j=='U') {
					if(x2!=x || y2+1!=y) ++y2;
				}
				if(j=='D') {
					if(x2!=x || y2-1!=y) --y2;
				}
				if(j=='R') {
					if(x2+1!=x || y2!=y) ++x2;
				}
				if(j=='L') {
					if(x2-1!=x || y2!=y) --x2;
				}
			}
			if(x2==0 && y2==0) {
				cout << x << " " << y << '\n';
				ans=true;
				break;
			}
		}
		if(x==0 && y==0) {
			cout << "10000000 10000000\n";
			continue;
		}
		if(!ans) {
			cout << "0 0\n";
		}
	}
}