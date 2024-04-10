#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

int ccw(int x0, int y0, int x1, int y1, int x2, int y2)
{
	long long crossProd = 1ll * (x1 - x0) * (y2 - y0) - 1ll * (x2 - x0) * (y1 - y0);
	if (crossProd < 0) return -1;
	if (crossProd > 0) return 1;
	return 0;
}

struct Hull
{
    map<int, int> mp;
    bool inside(int x, int y)
    {
        map<int, int>::iterator it = mp.lower_bound(x);
        if (it == mp.end()) return 0;
        if (it->first == x) return y <= it->second;
        if (it == mp.begin()) return 0;
        map<int, int>::iterator it1 = it; --it1;
        return ccw(it1->first, it1->second, it->first, it->second, x, y) <= 0;
    }

    void add(int x, int y)
    {
        if (inside(x, y)) return;
        mp[x] = y;

        while (true) {
            map<int, int>::iterator it = mp.find(x);
            if (it == mp.begin()) break;
            map<int, int>::iterator it1 = it; --it1;
            if (it1 == mp.begin()) break;
            map<int, int>::iterator it2 = it1; --it2;

            if (ccw(it->first, it->second, it2->first, it2->second, it1->first, it1->second) >= 0) {
                mp.erase(it1);
            } else break;
        }

        while (true) {
            map<int, int>::iterator it = mp.find(x);
            map<int, int>::iterator it1 = it; ++it1;
            if (it1 == mp.end()) break;
            map<int, int>::iterator it2 = it1; ++it2;
            if (it2 == mp.end()) break;

            if (ccw(it->first, it->second, it2->first, it2->second, it1->first, it1->second) <= 0) {
                mp.erase(it1);
            } else break;
        }

//        cerr << "A\n";
//        for (auto a : mp) cerr << a.first << ' ' << a.second << endl;
//        cerr << endl;
    }
};

int main()
{
	ios_base::sync_with_stdio(0);
    int q; cin >> q;

    Hull up, down;
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
			up.add(x, y);
			down.add(x, -y);
        } else {
            cout << (up.inside(x, y) && down.inside(x, -y) ? "YES\n" : "NO\n");
        }
    }

//    for (auto a : up.mp) cerr << a.first << ' ' << a.second << "; ";
//    cerr << endl;
//    for (auto a : down.mp) cerr << a.first << ' ' << -a.second << "; ";
//    cerr << endl;
}