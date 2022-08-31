#include <iostream>

int main() {
	std::string s;
	std::cin >> s;
	
	int n = s.length();
	int k = 26;
	
	int c[n][k];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < k; j++) {
			c[i][j] = 0;
			if(i) c[i][j] = c[i-1][j];
		}
		c[i][s[i]-'a']++;
	}
	
	int q;
	std::cin >> q;
	
	while(q--) {
		int l, r;
		std::cin >> l >> r;
		l--; r--;
		
		if(l == r) {
			std::cout << "Yes" << std::endl;
			continue;
		}
		
		int cur[k];
		for(int i = 0; i < k; i++) {
			cur[i] = c[r][i];
			if(l) cur[i] -= c[l-1][i];
		}
		
		bool poss = true;
		int nz = 0;
		for(int i = 0; i < k; i++) {
			if(cur[i])
				nz++;
		}
		
		if(nz == 1)
			poss = false;
		if(nz == 2)
			poss = (s[l] != s[r]);
		
		if(poss)
			std::cout << "Yes";
		else
			std::cout << "No";
		std::cout << std::endl;
	}
	
	return 0;
}