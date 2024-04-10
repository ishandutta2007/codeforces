#include <bits/stdc++.h>

using namespace std;

const int MX = 100000;

int fwt[MX + 1];

void fwt_add(int x, int d) {
	x++;
	while (x <= MX) {
		fwt[x] += d;
		x += x & -x;
	}
}

int fwt_get(int x) {
	x++;
	int r = 0;
	while (x) {
		r += fwt[x];
		x -= x & -x;
	}
	
	return r;
}

int main() {
	int n;
	ignore = scanf("%d", &n);
	
	vector<pair<int, int>> vec;
	for (int i = 0; i < n; i++) {
		int a;
		ignore = scanf("%d", &a);
		
		vec.emplace_back(a, i);
		
		fwt_add(i, +1);
	}
	
	sort(vec.begin(), vec.end());
	
	int p = -1;
	long long ans = 0;
	for (int i = 0; i < n;) {
		int j = i;
		while (j + 1 < n && vec[j + 1].first == vec[i].first) j++;
		
		int next = j + 1;
		
		while (j > i && vec[j - 1].second > p) j--;
		
		if (vec[j].second > p) {
			int jj = j;
			while (j < n && vec[j].first == vec[i].first) {
				ans += fwt_get(vec[j].second) - fwt_get(p);
				p = vec[j].second;
				fwt_add(p, -1);
				
				j++;
			}
			
			j = jj - 1;
		}
		
		if (i <= j) {
			ans += fwt_get(n - 1) - fwt_get(p) + fwt_get(vec[i].second);
			p = vec[i].second;
			fwt_add(p, -1);
			
			i++;
		}
		
		while (i <= j) {
			ans += fwt_get(vec[i].second) - fwt_get(p);
			p = vec[i].second;
			fwt_add(p, -1);
			
			i++;
		}
		
		i = next;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}