#include <iostream>
#include <vector>

#define int long long

signed main() {
	int n;
	std::cin >> n;
	
	int y[n];
	for(int i = 0; i < n; i++) {
		std::cin >> y[i];
	}
	
	bool poss = false;
	
	int cur;
	for(int i = 1; i < n; i++) {
		cur = y[i]-y[0];
		std::vector<int> inv;
		for(int j = 1; j < n; j++) {
			if(i == j)
				continue;
			if(j*(cur) != (y[j]-y[0])*i)
				inv.push_back(j);
		}
		if(inv.size()) {
			if(inv.size() <= 1)
				poss = true;
			int next = y[inv[1]]-y[inv[0]];
			int nextx = inv[1]-inv[0];
			bool idea = true;
			for(int j = 1; j < inv.size(); j++) {
				if((inv[j]-inv[0])*cur != (y[inv[j]]-y[inv[0]])*i)
					idea = false;
			}
			if(idea)
				poss = true;
		}
	}
	
	bool idea = true;
	for(int i = 3; i < n; i++) {
		if((y[i]-y[1])*(2-1) != (y[2]-y[1])*(i-1))
			idea = false;
	}
	
	bool idea1 = true;
	for(int i = 1; i < n; i++) {
		if((y[i]-y[0])*(2-0) != (y[2]-y[0])*(i-0))
			idea1 = false;
	}
	if((poss || idea) && !idea1)
		std::cout << "Yes";
	else
		std::cout << "No";
	return 0;
	
}