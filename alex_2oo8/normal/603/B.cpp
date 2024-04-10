#include<bits/stdc++.h>

using namespace std;

const int md = 1000000007;

bool ok[1000000];

int main() {
	int p, k;
	scanf("%d %d", &p, &k);
	
	for (int i = 0; i < p; i++) ok[i] = true;
	
	int ans = 0;
	for (int i = 0; i < p; i++)
		if ((i * 1LL * k) % p == i)
			ans += 1;
	
	ok[0] = false;
	for (int i = 0; i < p; i++)
		if (ok[i]) {
			ans = (ans * 1LL * p) % md;
			
			int j = i;
			while (ok[j]) {
				ok[j] = false;
				
				j = (j * 1LL * k) % p;
			}
		}
	
	printf("%d\n", ans);
	
	return 0;
}