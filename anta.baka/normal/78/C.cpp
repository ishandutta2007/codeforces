#include <bits/stdc++.h>

using namespace std;

int n, m, k;
map<int, int> mem;

void solve(int x) {
	if(mem.count(x))
		return;
	mem[x] = 0;
	if(x == 1)
		return;
	for(int y = 1; y * y <= x; y++)
		if(x % y == 0) {
			int y1 = x / y;
			if(y >= k) {
				if(y1 % 2 == 0) {
					mem[x] = 1;
					return;
				}
				solve(y);
				if(mem[y] == 0) {
					mem[x] = 1;
					return;
				}
			}
			if(y != 1 && y1 >= k) {
				if(y % 2 == 0) {
					mem[x] = 1;
					return;
				}
				solve(y1);
				if(mem[y1] == 0) {
					mem[x] = 1;
					return;
				}
			}
		}
}

int main() {
	cin >> n >> m >> k;
	if(n % 2 == 0)
		return cout << "Marsel", 0;
	solve(m);
	cout << (mem[m] != 0 ? "Timur" : "Marsel");
}