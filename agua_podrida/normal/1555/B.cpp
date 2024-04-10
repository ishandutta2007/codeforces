#define ll long long

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(ll i = 0; i < n; ++i)
#define forll(i, s, n) for(ll i = s; i < n; ++i)
#define pb(a) push_back(a)
#define all(v) v.begin(),v.end()

using namespace std;

int main () {
	cin.tie(0);
	ll t;
	long long W, H, x1, y1, x2, y2, w, h, distance;
	long long upper_space, lower_space, right_space, left_space;
	cin >> t;
	forn(i, t) {
		cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
		if ((W < ((x2 - x1) + w)) and (H < ((y2 - y1) + h))) {
			distance = -1;
		}
		else if (W < ((x2 - x1) + w)) {
			upper_space = H - y2;
			lower_space = y1;
			if ((upper_space >= h) or (lower_space >= h)) {
				distance = 0;
			} else distance = min(h-upper_space, h-lower_space);
		} else if (H < ((y2 - y1) + h)) {
			right_space = W - x2;
			left_space = x1;
			if ((right_space >= w) or (left_space >= w)) {
				distance = 0;
			} else distance = min(w-right_space, w-left_space);
		} else {
			upper_space = H - y2;
			lower_space = y1;
			right_space = W - x2;
			left_space = x1;
			if ((upper_space >= h) or (lower_space >= h)) {
				distance = 0;
			} else if ((right_space >= w) or (left_space >= w)) {
				distance = 0;
			} else {
				distance = min(w-right_space, w-left_space);
				distance = min(distance, h-upper_space);
				distance = min(distance, h-lower_space);
			}
		}
		cout << distance << "\n";
	}
}