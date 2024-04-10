#include <iostream>

int main() {
	int n, q;
	std::cin >> n >> q;
	
	bool state[2][n];
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < n; j++)
				state[i][j] = 0;
	
	int block = 0;
	for(int i = 0; i < q; i++) {
		int x, y;
		std::cin >> x >> y; x--; y--;
		if(state[x][y]) {
			for(int k = -1; k < 2; k++) {
				if(0 <= y+k && y+k < n)
					block -= state[1-x][y+k];
			}
		} else {
			for(int k = -1; k < 2; k++) {
				if(0 <= y+k && y+k < n)
					block += state[1-x][y+k];
			}
		}
		state[x][y] = !state[x][y];
		
		if(block > 0)
			std::cout << "No";
		else
			std::cout << "Yes";
		std::cout << std::endl;
	}
	
	return 0;
}