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

typedef long double ld;

const ld inf = 1e7;

void fail(){
	cout << -1 << endl;
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if(x1 > x2) swap(x1,x2);
	if(y1 > y2) swap(y1,y2);

	ld mn = 0, mx = inf;

	rep(_,0,n){
		int rx, ry, vx, vy;
		cin >> rx >> ry >> vx >> vy;

		if(vx == 0){
			if(x1 >= rx || x2 <= rx) fail();
		} else {
			ld lo = x1-rx, hi = x2 - rx;
			if(vx < 0){
				vx *= -1;
				lo *= -1;
				hi *= -1;
				swap(lo, hi);
			}
			lo /= vx, hi /= vx;
			mn = max(mn, lo);
			mx = min(mx, hi);
		}
		if(vy == 0){
			if(y1 >= ry || y2 <= ry) fail();
		} else {
			ld lo = y1-ry, hi = y2 - ry;
			if(vy < 0){
				vy *= -1;
				lo *= -1;
				hi *= -1;
				swap(lo, hi);
			}
			lo /= vy, hi /= vy;
			mn = max(mn, lo);
			mx = min(mx, hi);
		}
	}
	if(mx <= mn+1e-15) fail();
	cout.precision(8);
	cout << mn << endl;
}