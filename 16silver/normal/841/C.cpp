#include <cstdio>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int>> B;
vector<int> A;
int C[200000];
int main() {
	int n, i, t;
	pair<int,int> tmp;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &t);
		A.push_back(t);
	}
	for (i = 0; i < n; i++) {
		scanf("%d", &t);
		tmp.first = t;
		tmp.second = i;
		B.push_back(tmp);
	}
	sort(B.begin(), B.end());
	sort(A.begin(), A.end(), greater<int>());
	for (i = 0; i < n; i++) {
		C[B[i].second] = A[i];
	}
	for (i = 0; i < n; i++) printf("%d ", C[i]);
}