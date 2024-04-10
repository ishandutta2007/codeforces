#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N;
char s[MAXN];
vector <int> pos[30];

int main() {
	scanf("%s", s);
	N = strlen(s);
	for (int i = 0; i < 26; i++) 
		pos[i].push_back(-1);
	for (int i = 0; i < N; i++)
		pos[s[i] - 'a'].push_back(i);
	for (int i = 0; i < 26; i++)
		pos[i].push_back(N);
		
	int sol = N;
	for (int i = 0; i < 26; i++) {
		int mx = 0;
		for (int j = 1; j < pos[i].size(); j++) 
			mx = max(mx, pos[i][j] - pos[i][j - 1]);
		sol = min(sol, mx);
	}
	
	printf("%d\n", sol);
	
	return 0;
}