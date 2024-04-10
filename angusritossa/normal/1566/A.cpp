#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		int n, s;
		scanf("%d%d", &n, &s);
		int mid = (n+2)/2;
		printf("%d\n", s/mid);	
	}
}