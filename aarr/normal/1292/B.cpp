#include <bits/stdc++.h>
#define int long long
using namespace std;

const long long inf = 20ll * 1000 * 1000 * 1000 * 1000 * 1000 + 5;

vector <pair <long long, long long> > vec;
long long dis(long long x1, long long y1, long long x2, long long y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}
int32_t main() {
	ios :: sync_with_stdio(false);
	long long x0, y0, ax, ay, bx, by, sx, sy, t;
	cin >> x0 >> y0 >> ax >> ay >> bx >> by >> sx >> sy >> t;
	while (x0 < inf && y0 < inf) {
		vec.push_back({x0, y0});
		x0 *= ax;
		x0 += bx;
		y0 *= ay;
		y0 += by;
	}
	int n = vec.size(), ans = 0;
	for (int i = 0; i < n; i++) {
		//if (2ll * dis(sx, sy, vec[i].first, vec[i].second) <= t) {
		//	ans = max(ans, 1);
		//}
	//	cout << vec[i].first << " " << vec[i].second << endl;
		for (int j = i; j < n; j++) {
			for (int q = i; q < j; q++) {
				long long s = 0;
			//	long long x = dis(sx, sy, vec[q].first, vec[q].second) + dis(vec[q + 1].first, vec[q + 1].second, vec[i].first, vec[i].second) + dis(sx, sy, vec[j].first, vec[j].second);
			//	long long y = dis(sx, sy, vec[q].first, vec[q].second) + dis(vec[j].first, vec[j].second, vec[i].first, vec[i].second) + dis(sx, sy, vec[q + 1].first, vec[q + 1].second);
			//	long long z = dis(sx, sy, vec[q].first, vec[q].second) + dis(vec[j].first, vec[j].second, vec[i].first, vec[i].second) + dis(sx, sy, vec[q + 1].first, vec[q + 1].second);
			//	long long w = dis(sx, sy, vec[q].first, vec[q].second) + dis(vec[j].first, vec[j].second, vec[q].first, vec[q].second) + dis(sx, sy, vec[q + 1].first, vec[q + 1].second)
				long long x = dis(sx, sy, vec[q].first, vec[q].second) + dis(vec[q + 1].first, vec[q + 1].second, vec[i].first, vec[i].second);
				long long z = dis(sx, sy, vec[q + 1].first, vec[q + 1].second) + dis(vec[q].first, vec[q].second, vec[j].first, vec[j].second);
				s = min(x, z);
				
			//	cout << "73 " << i << " " << j << " " << q << " " << vec[i].first << " " << vec[i].second << " " << s << endl;				
				
				for (int k = i + 1; k <= q; k++) {
					s += dis(vec[k].first, vec[k].second, vec[k - 1].first, vec[k - 1].second);
				}
				for (int k = q + 2; k <= j; k++) {
					s += dis(vec[k].first, vec[k].second, vec[k - 1].first, vec[k - 1].second);
				}
				if (s <= t) {
					ans = max(ans, j - i + 1);
				}
			//	cout << i << " " << j << " " << vec[i].first << " " << vec[i].second << " " << s << endl;					
			}
			long long s = min(dis(sx, sy, vec[i].first, vec[i].second), dis(sx, sy, vec[j].first, vec[j].second));
			for (int k = i + 1; k <= j; k++) {
				s += dis(vec[k].first, vec[k].second, vec[k - 1].first, vec[k - 1].second);
			}
			if (s <= t) {
				ans = max(ans, j - i + 1);
			}
		}
	}
	cout << ans << endl;
	return 0;
}