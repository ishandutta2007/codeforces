#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

void mark1(string &s) {
	for (char &c : s)
	if (c == '.')
		c = '!';
}

struct Grid {
	string f, g, h;
	bool full() {
		for (int i = 0; i < 3; ++i)
		if (f[i] == '.' || g[i] == '.' || h[i] == '.')
			return false;
		return true;
	}

	void mark() {
		mark1(f);
		mark1(g);
		mark1(h);
	}
};

int main() {
	Grid grid[9];
	cin >> grid[0].f >> grid[1].f >> grid[2].f;
	cin >> grid[0].g >> grid[1].g >> grid[2].g;
	cin >> grid[0].h >> grid[1].h >> grid[2].h;


	cin >> grid[3].f >> grid[4].f >> grid[5].f;
	cin >> grid[3].g >> grid[4].g >> grid[5].g;
	cin >> grid[3].h >> grid[4].h >> grid[5].h;


	cin >> grid[6].f >> grid[7].f >> grid[8].f;
	cin >> grid[6].g >> grid[7].g >> grid[8].g;
	cin >> grid[6].h >> grid[7].h >> grid[8].h;

	int x, y;
	cin >> x >> y;
	--x;
	--y;
	int X = x / 3;
	int Y = y / 3;
	int C = X * 3 + Y;
	x %= 3;
	y %= 3;
	int c = x * 3 + y;
	if (grid[c].full()) {
		for (int i = 0; i < 9; ++i)
			grid[i].mark();
	}
	else
		grid[c].mark();


	cout << grid[0].f << ' ' << grid[1].f << ' ' << grid[2].f << '\n';
	cout << grid[0].g << ' ' << grid[1].g << ' ' << grid[2].g << '\n';
	cout << grid[0].h << ' ' << grid[1].h << ' ' << grid[2].h << '\n';
	cout << '\n';

	cout << grid[3].f << ' ' << grid[4].f << ' ' << grid[5].f << '\n';
	cout << grid[3].g << ' ' << grid[4].g << ' ' << grid[5].g << '\n';
	cout << grid[3].h << ' ' << grid[4].h << ' ' << grid[5].h << '\n';
	cout << '\n';


	cout << grid[6].f << ' ' << grid[7].f << ' ' << grid[8].f << '\n';
	cout << grid[6].g << ' ' << grid[7].g << ' ' << grid[8].g << '\n';
	cout << grid[6].h << ' ' << grid[7].h << ' ' << grid[8].h << '\n';
	cout << '\n';
	return 0;
}