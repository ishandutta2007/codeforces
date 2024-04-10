#include<bits/stdc++.h>

using namespace std;

const int MX = 150000;

int a[MX], n;
vector<int> bad, pos;
set< pair<int, int> > ans;

bool check(int i) {
	if (i < 0 || i >= n - 1) return true;
	if (i % 2 == 0 && a[i] >= a[i + 1]) return false;
	if (i % 2 == 1 && a[i] <= a[i + 1]) return false;
	
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	
	for (int i = 0; i + 1 < n; i++) {
		if (check(i) == false) {
			bad.push_back(i);
			bad.push_back(i + 1);
			
			pos.push_back(i);
			pos.push_back(i + 1);
		}
	}
	
	if (bad.size() > 10) {
		printf("0\n");
		
		return 0;
	}
	
	for (int x : pos)
		for (int y = 0; y < n; y++) {
			if (x == y) continue;
			
			swap(a[x], a[y]);
			
			bool ok = true;
			bad.push_back(y);
			bad.push_back(y - 1);
			for (int i : bad) {
				if (check(i - 1) == false || check(i) == false) ok = false;
			}
			bad.pop_back();
			bad.pop_back();
			
			if (ok) ans.emplace(min(x, y), max(x, y));
			
			swap(a[x], a[y]);
		}
	
	printf("%d\n", (int)ans.size());
	
	return 0;
}