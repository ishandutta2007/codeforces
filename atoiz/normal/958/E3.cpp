//https://codeforces.com/contest/958/submission/37324641

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cassert>

using namespace std;
using LD = long double;

struct Point
{
    LD x, y;
    Point operator+ (const Point &p) const { return {x + p.x, y + p.y}; }
    Point operator- (const Point &p) const { return {x - p.x, y - p.y}; }
    Point operator* (const LD &t) const { return {x * t, y * t}; }
    Point operator/ (const LD &t) const { return {x / t, y / t}; }
    LD operator* (const Point &p) const { return x * p.x + y * p.y; }
    LD operator^ (const Point &p) const { return x * p.y - y * p.x; }
    bool operator== (const Point &p) const { return x == p.x && y == p.y; }
    LD norm() const { return (*this) * (*this); }
    LD dist2 (const Point &p) const { return ((*this) - p).norm(); }
    int ccw(const Point &p1, const Point &p2) const
    {
        LD cp = (p1 - *this) ^ (p2 - *this);
        if (cp < 0) return -1;
        if (cp > 0) return 1;
        return 0;
    }
};
const LD EPS = 1e-7;
const Point BASE = {0, 0}, SOME_POINT = {1e-5, 1e-5};
istream& operator>> (istream &fin, Point &p) { return fin >> p.x >> p.y; }

struct Object
{
    Point p; int id, type;
    bool operator< (const Object &obj) const
    {
        const Point& q = obj.p;
        bool b1 = p.y > 0 || (p.y == 0 && p.x >= 0);
        bool b2 = q.y > 0 || (q.y == 0 && q.x >= 0);
        if (b1 != b2) return b1;
        int _ccw = BASE.ccw(p, q);
        if (_ccw != 0) return _ccw > 0;
        return p.norm() < q.norm();
    }
};

const int MAX = 10001;
int ans[MAX];

void solve(vector<Object> objs)
{
//	cerr << "Start: " << objs.size() << endl;
    if (objs.size() == 2) {
        if (objs[0].type < 0) swap(objs[0], objs[1]);
        ans[objs[0].id] = objs[1].id;
        return;
    }

	int n = objs.size();
	Point mid = BASE;
//	for (int i = 0; i < n; ++i) cerr << '(' << objs[i].p.x << ", " << objs[i].p.y << "), "; cerr << endl;
    for (Object &obj : objs) mid = mid + obj.p; mid = mid / n - SOME_POINT;
    for (Object &obj : objs) obj.p = obj.p - mid;
//	for (int i = 0; i < n; ++i) cerr << '(' << objs[i].p.x << ", " << objs[i].p.y << "), "; cerr << endl;
	sort(objs.begin(), objs.end());
//	for (int i = 0; i < n; ++i) cerr << '(' << objs[i].p.x << ", " << objs[i].p.y << "), "; cerr << endl;
//	for (int i = 0; i < n; ++i) cerr << '(' << objs[i].type << "), "; cerr << endl;

	int tail = 0, sum = 0;
    for (int head = 0; head < n; ++head) {
        while (true) {
            LD _ccw = (objs[head].p - BASE) ^ (objs[head].p - objs[tail].p);
			if (_ccw > EPS) break;
            if (abs(_ccw) <= EPS && ((objs[head].p.x * objs[tail].p.x < 0) || (objs[head].p.y * objs[tail].p.y < 0))) break;
//            if (abs(_ccw) <= EPS && (objs[head].p.y == objs[tail].p.y ? objs[head].p.x < objs[tail].p.x : objs[head].p.y < objs[tail].p.y)) break;

            sum += objs[tail].type;
            if (++tail == n) tail = 0;
        }

        if (sum == 0) {
            vector<Object> v1, v2;
            v1.reserve((n + tail - head) % n);
            v2.reserve((n + head - tail) % n);
            for (int i = head; i != tail; i = (i + 1) % n) v1.push_back(objs[i]);
            for (int i = tail; i != head; i = (i + 1) % n) v2.push_back(objs[i]);
            solve(v1); solve(v2);
//			cerr << "End: " << objs.size() << endl << endl;
			return;
        }
        sum -= objs[head].type;
    }
	for (int i = 0; i < n; ++i) cout << '(' << objs[i].p.x << ", " << objs[i].p.y << "), "; cout << endl;
    exit(0);
}

int32_t main()
{
//	freopen("test.inp", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<Object> objs(2*n);
    for (int i = 0; i < n; ++i) {
		cin >> objs[i].p;
		objs[i].id = i, objs[i].type = 1;
    }
    for (int i = 0; i < n; ++i) {
		cin >> objs[n+i].p;
		objs[n+i].id = i, objs[n+i].type = -1;
    }

    solve(objs);
    for (int i = 0; i < n; ++i) cout << ans[i] + 1 << '\n';
}