#include <bits/stdc++.h>
using namespace std;

map <int, int> cnt;

int main() {
	int N;
	scanf("%d", &N);
	while (N--) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	
	for (auto it : cnt)
		if (it.second % 2) {
			puts("Conan");
			return 0;
		}
	
	puts("Agasa");
	
	return 0;
}