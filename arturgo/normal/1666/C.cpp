#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#define int long long
using namespace std;

struct Segment {
	int x1, y1, x2, y2;
};

vector<Segment> segments;
vector<pair<int, int>> points;

set<pair<int, int>> vus;

int explore(pair<int, int> point) {
	if(vus.count(point)) return 0;
	vus.insert(point);
	
	int res = 0;
	
	for(pair<int, int> p : points) if(p == point) res++;
	
	for(Segment seg : segments) {
		if(seg.x1 == point.first && seg.y1 == point.second) {
			res += explore({seg.x2, seg.y2});
		}
		if(seg.x2 == point.first && seg.y2 == point.second) {
			res += explore({seg.x1, seg.y1});
		}
	}
	
	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<int> xs, ys;
	for(int i = 0;i < 3;i++) {
		int x, y;
		cin >> x >> y;
		
		points.push_back({x, y});
		
		xs.push_back(x);
		ys.push_back(y);
	}
	
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());
	
	int bestDist = 1000ll * 1000 * 1000 * 1000ll;
	vector<Segment> bests;
	
	for(int n = 0;n < (1 << 12);n++) {
		bitset<12> bits(n);
		segments.clear();
		vus.clear();
		
		if(bits[0]) segments.push_back({xs[0], ys[0], xs[0], ys[1]});
		if(bits[1]) segments.push_back({xs[1], ys[0], xs[1], ys[1]});
		if(bits[2]) segments.push_back({xs[2], ys[0], xs[2], ys[1]});
		if(bits[3]) segments.push_back({xs[0], ys[1], xs[0], ys[2]});
		if(bits[4]) segments.push_back({xs[1], ys[1], xs[1], ys[2]});
		if(bits[5]) segments.push_back({xs[2], ys[1], xs[2], ys[2]});
		if(bits[6]) segments.push_back({xs[0], ys[0], xs[1], ys[0]});
		if(bits[7]) segments.push_back({xs[0], ys[1], xs[1], ys[1]});
		if(bits[8]) segments.push_back({xs[0], ys[2], xs[1], ys[2]});
		if(bits[9]) segments.push_back({xs[1], ys[0], xs[2], ys[0]});
		if(bits[10]) segments.push_back({xs[1], ys[1], xs[2], ys[1]});
		if(bits[11]) segments.push_back({xs[1], ys[2], xs[2], ys[2]});
		
		if(explore(points[0]) != 3) continue;
		
		int score = 0;
		for(Segment seg : segments) {
			score += abs(seg.x1 - seg.x2) + abs(seg.y1 - seg.y2);
		}
		
		if(score < bestDist) {
			bests = segments;
			bestDist = score;
		}
	}
	
	cout << bests.size() << endl;
	
	for(Segment seg : bests) {
		cout << seg.x1 << " " << seg.y1 << " " << seg.x2 << " " << seg.y2 << endl;
	}
	return 0;
}