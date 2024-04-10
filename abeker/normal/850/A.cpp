#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 1005;

int N;
int a[MAXN][10];

int main() {
	scanf("%d", &N);
	if (N > 200) {
		puts("0");
		return 0;
	}
	
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < 5; j++)
			scanf("%d", a[i] + j);
	
	vector <int> sol;
	for (int i = 0; i < N; i++) {
		bool good = true;
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				if (i != j && j != k && k != i) {
					int dot = 0;
					for (int l = 0; l < 5; l++)
						dot += (a[i][l] - a[j][l]) * (a[i][l] - a[k][l]);
					if (dot > 0) 
						good = false;
				}
		if (good)
			sol.push_back(i);
	}
	
	printf("%d\n", sol.size());
	for (auto it : sol)
		printf("%d ", it + 1);
	
	return 0;
}