#include <iostream>
#include <vector>
#include <set>

int main() {
	int n;
	std::cin >> n;
	
	std::vector<int> pow(n, 0);
	std::vector<int> deg(n, 0);
	std::vector<int> seq(n-1, 0);
	std::set<std::pair<int, int> > s;
	
	for(int i = 0; i < n-1; i++) {
		std::cin >> seq[i];
		seq[i]--;
		deg[seq[i]]++;
		pow[i+1] = i+1;
	}
	
	std::cout << seq[0]+1 << std::endl;
	
	for(int i = 0; i < n; i++) {
		if(deg[i] == 0)
			s.insert({pow[i], i});
	}
	
	for(int i = n-2; i >= 0; i--) {
		int cur = seq[i];
		int child = (*s.begin()).second;
		s.erase(s.begin());
		pow[cur] = std::max(pow[cur], pow[child]);
		deg[cur]--;
		if(deg[cur] == 0)
			s.insert({pow[cur], cur});
		std::cout << cur+1 << " " << child+1 << std::endl;
	}
	
	return 0;
}