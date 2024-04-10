#include <bits/stdc++.h> 

using namespace std;

int main (int argc, char const *argv[]) {
	int pos = 0, n, t;
	string dir;
	int f = 1;
	cin >> n; while (n--) {
		cin >> t >> dir;
		if (f == 0) continue;
		if (pos == 0 and dir != "South") {
			f = 0;
			continue;
		}
		if (pos == 20000 and dir != "North") {
			f = 0;
			continue;
		}
		if (dir == "North") {
			if (t > pos) {
				f = 0;
			} else {
				pos -= t;
			}
			continue;
		} 
		if (dir == "South") {
			if (pos + t > 20000) {
				f = 0;
			} else {
				pos += t;
			}
			continue;
		}
	}
	if (pos != 0) f = 0;
	puts(f ? "YES" : "NO");
	return 0;
}