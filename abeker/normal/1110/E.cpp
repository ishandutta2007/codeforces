#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N;
int a[MAXN], b[MAXN];
vector <int> c, d;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", a + i);
		if (i)
			c.push_back(a[i] - a[i - 1]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", b + i);
		if (i)
			d.push_back(b[i] - b[i - 1]);
	}
	
	sort(c.begin(), c.end());
	sort(d.begin(), d.end());
	
	puts(a[0] == b[0] && c == d ? "Yes" : "No");
	
	return 0;
}