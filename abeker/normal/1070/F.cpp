#include <bits/stdc++.h>
using namespace std;

vector <int> a[2][2];

int main() {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++) 
			a[i][j].push_back(0);
			
	int N;
	scanf("%d", &N);
	while (N--) {
		char s[5];
		int x;
		scanf("%s%d", s, &x);
		a[s[0] - '0'][s[1] - '0'].push_back(x);
	}
	
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++) {
			sort(a[i][j].begin() + 1, a[i][j].end(), greater <int> ());
			for (int k = 1; k < a[i][j].size(); k++)
				a[i][j][k] += a[i][j][k - 1];
		}
	
	if (a[0][1].size() > a[1][0].size())
		swap(a[0][1], a[1][0]);
		
	int ans = 0;
	for (int i = 0; i < min(a[0][0].size(), a[1][1].size()); i++) 
		ans = max(ans, a[0][0][i] + a[0][1].back() + a[1][0][min(a[0][1].size() + a[1][1].size() - i - 1, a[1][0].size()) - 1]);
	
	printf("%d\n", ans + a[1][1].back());
	
	return 0;
}