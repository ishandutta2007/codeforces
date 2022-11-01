#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cassert>
#include <bitset>
#include <fstream>
#include <stack>
#include <cstdlib>

using namespace std;

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double


int main() {
	//srand(time(NULL));
	#ifdef LOCAL
		//gen();
		freopen("a.in", "r", stdin);
		//freopen("a.out", "w", stdout);
		cout << endl << endl;
	#else
		//freopen("whats.in", "r", stdin);
		//freopen("whats.out", "w", stdout);
	#endif
	//check();
	
	ios_base::sync_with_stdio(false);
	
	
	int n;
	cin >> n;
	set < pair < int, int > > s;
	s.insert(mp(1, 2e9));
	while (n--) {
		int x, y;
		cin >> x >> y;
		auto it = s.upper_bound(mp(x, 2e9));
		it--;
		auto f = *it;
		if (f.fst <= x && f.snd >= x + y - 1) {
			cout << x << " " << x + y - 1 << "\n";
			s.erase(f);
			s.insert(mp(f.fst, x - 1));
			s.insert(mp(x + y, f.snd));
		}
		else {
			for (auto f: s) {
				if (f.snd - f.fst + 1 >= y) {
					cout << f.fst << " " << f.fst + y - 1 << "\n";
					s.erase(f);
					s.insert(mp(f.fst, f.fst-1));
					s.insert(mp(f.fst + y, f.snd));
					break;
				}
			}
		}
	}
	
	return 0;
}