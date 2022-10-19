#include <bits/stdc++.h>
using namespace std;

int N;
vector <int> a;

int main() {
	scanf("%d", &N);
	a.resize(N);		
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	
	int ans = 0;	
	for (; !a.empty(); ans++) {
		int mini = *min_element(a.begin(), a.end());
		vector <int> b;
		for (auto it : a)
			if (it % mini)
				b.push_back(it);
		a = b;
	}
	
	printf("%d\n", ans);
	
	return 0;
}