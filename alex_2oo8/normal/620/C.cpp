#include<bits/stdc++.h>

using namespace std;

const int MX = 1000000;

int p[MX], k = 0;
set<int> s;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		
		if (s.count(a) == 0) s.insert(a);
		else {
			p[k++] = i + 1;
			
			s.clear();
		}
	}
	
	if (k == 0) printf("-1\n");
	else {
		p[k - 1] = n;
		
		printf("%d\n", k);
		printf("1 %d\n", p[0]);
		for (int i = 0; i < k - 1; i++) printf("%d %d\n", p[i] + 1, p[i + 1]);
	}
	
	return 0;
}