#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

#define int long long
#define MOD 1000000007

signed main() {
	int n, m;
	std::cin >> n >> m;
	
	int a[n];
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	
	std::pair<int, std::pair<int, int> > man[m];
	for(int i = 0; i < m; i++) {
		std::cin >> man[i].second.second >> man[i].first;
		man[i].second.second--;
		man[i].first--;
		man[i].second.first = i;
	}
	
	std::vector<int> stack(n);
	int top = -1;
	for(int i = 0; i < m; i++) {
		while(top > -1 && man[stack[top]] < man[i])
			top--;
		
		stack[++top] = i;
	}
	
	
	
	int max = man[stack[0]].first + 1;
	std::sort(a, a+max);
	
	int l = 0; int r = man[stack[0]].first;
	
	int change[n];
	
	for(int i = 0; i < top; i++) {
		int u = stack[i];
		int v = stack[i+1];
	
		
		for(int j = man[u].first; j > man[v].first; j--) {
			if(man[u].second.second) {
				change[j] = a[l++];
			}
			else
				change[j] = a[r--];
		}
	}
	
	int u = stack[top];

	
	for(int i = man[u].first; i >= 0; i--) {
		if(man[u].second.second) {
			change[i] = a[l++];
		}
		else
			change[i] = a[r--];
	}
	
	for(int i = 0; i < max; i++)
		std::cout << change[i] << " ";
	for(int i = max; i < n; i++)
		std::cout << a[i] << " ";
	
}