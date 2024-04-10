#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

int main () {
	int xx1, xx2, yy1, yy2;
	cin >> xx1 >> yy1 >> xx2 >> yy2;
	fop (i,0,2) {
		int x1,x2,y1,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 <= xx1 and xx2 <= x2) {
			if (y1 <= yy1 and yy1 <= y2) yy1 = min({yy2, y2});
			if (y2 >= yy2 and yy2 >= y1) yy2 = max({yy1, y1});
		} if (y1 <= yy1 and yy2 <= y2) {
			if (x1 <= xx1 and xx1 <= x2) xx1 = min({xx2, x2});
			if (x2 >= xx2 and xx2 >= x1) xx2 = max({xx1, x1});
		}
	}
	if (xx1 >= xx2 or yy1 >= yy2) {
		cout << "NO" << endl; 
	} else {
		cout << "YES" << endl;
	}
}