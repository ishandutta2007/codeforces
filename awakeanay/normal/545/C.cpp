#include <iostream>

int main() {
	int n;
	std::cin >> n;
	
	int x[n], h[n];
	for(int i = 0; i < n; i++)
		std::cin >> x[i] >> h[i];
	
	int last[3];
	last[0] = last[2] = 1;
	last[1] = 0;
	for(int i = 1; i < n; i++) {
		int next[3];
		next[0] = next[1] = next[2] = 0;
		next[1] = std::max(last[0], last[1]);
		if(x[i-1] + h[i-1] < x[i])
			next[1] = std::max(next[1], last[2]);
		if(x[i-1] < x[i]-h[i])
			next[0] = std::max(next[0], std::max(last[1], last[0])+1);
		if(x[i-1]+h[i-1] < x[i]-h[i])
			next[0] = std::max(next[0], last[2]+1);
		next[2] = 1+std::max(last[0], last[1]);
		if(x[i-1] + h[i-1] < x[i])
			next[2] = std::max(next[2], 1+last[2]);
			
		for(int j = 0; j < 3; j++) {
			last[j] = next[j];
		}
	}
	
	std::cout << std::max(last[0], std::max(last[1], last[2]));
	
	return 0;
}