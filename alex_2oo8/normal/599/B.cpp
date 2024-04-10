#include<bits/stdc++.h>

using namespace std;

vector<int> v[200000];
int b[200000];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int f;
		scanf("%d", &f);
		
		v[f].push_back(i + 1);
	}
	
	bool ok = true;
	for (int i = 0; i < m; i++) {
		scanf("%d", b + i);
		
		if (v[b[i]].size() == 0) {
			printf("Impossible\n");
			
			return 0;
		}
		
		if (v[b[i]].size() > 1) ok = false;
		
		b[i] = v[b[i]][0];
	}
	
	if (!ok) {
		printf("Ambiguity\n");
		
		return 0;
	}
	
	printf("Possible\n");
	for (int i = 0; i < m; i++) printf("%d ", b[i]);
	printf("\n");
	
	return 0;
}