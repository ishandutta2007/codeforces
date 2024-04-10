#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAX = 1e9;

pii get(int id) {
	return id <= MAX ? pii(id, MAX) : pii(MAX, 2 * MAX - id);
}

int ask(int id) {
	pii tmp = get(id);
	printf("%d %d\n", tmp.first, tmp.second);
	fflush(stdout);
	char s[10];
	scanf("%s", s);
	return s[0] == 'b';
}

int main() {
	int N;
	scanf("%d", &N);
	
	int flag = ask(0);
	int lo = 1, hi = 2 * MAX;
	for (N--; N; N--) {
		int mid = lo + (hi - lo) / 2;
		if (ask(mid) ^ flag) 
			hi = mid;
		else
			lo = mid;	
	}
	
	pii ans = get(lo + (hi - lo) / 2);
	
	printf("%d %d %d %d\n", 0, 0, ans.first, ans.second);
	fflush(stdout);
	
	return 0;
}