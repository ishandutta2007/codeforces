#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, C[3];
int main() {
	int i, a;
	scanf("%d", &n);
	vector<int>Res;
	for (i = 1; i <= n; i++) {
		scanf("%d", &a);
		C[a]++;
	}
	if (!C[1] || !C[2]) {
		for (i = 1; i <= C[1]; i++)Res.push_back(1);
		for (i = 1; i <= C[2]; i++)Res.push_back(2);
		
	}
	else {
		Res.push_back(2);
		Res.push_back(1);
		C[2]--, C[1]--;
		for (i = 1; i <= C[2]; i++)Res.push_back(2);
		for (i = 1; i <= C[1]; i++)Res.push_back(1);
	}
	for (auto &x : Res)printf("%d ", x);
}