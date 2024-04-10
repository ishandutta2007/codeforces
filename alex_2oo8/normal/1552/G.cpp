#include <bits/stdc++.h>

using namespace std;

const int MX = 40, MK = 10;

int a[MX], save[MK][MX], n, k;
bool ans = true;
vector<int> ids[MK];

void brute(int i) {
	if (i == k) {
		int l = 0;
		while (l < n && a[l] == 1) l++;
		
		int r = n - 1;
		while (r >= 0 && a[r] == 0) r--;
		
		if (l < r) ans = false;
		
		return;
	}
	
	int t = 0, s = 0;
	for (int x : ids[i]) {
		save[i][x] = a[x];
		
		if (a[x] == -1) t++;
		else s += a[x];
	}
	
	for (int x = 0; x <= t; x++) {
		for (int j = 0; j < s + x; j++) {
			a[ids[i][j]] = 1;
		}
		
		for (size_t j = s + x; j < ids[i].size(); j++) {
			a[ids[i][j]] = 0;
		}
		
		brute(i + 1);
	}
	
	for (int x : ids[i]) {
		a[x] = save[i][x];
	}
}

int main() {
	ignore = scanf("%d %d", &n, &k);
	//n = 40;
	//k = 10;
	for (int i = 0, q; i < k; i++) {
		ignore = scanf("%d", &q);
		//q = 4 * (i + 1);
		for (int j = 0, x; j < q; j++) {
			ignore = scanf("%d", &x);
			//x = 1 + j;
			ids[i].push_back(x - 1);
		}
	}
	
	fill(a, a + n, -1);
	
	brute(0);
	
	printf("%s\n", (ans ? "ACCEPTED" : "REJECTED"));
	
	return 0;
}