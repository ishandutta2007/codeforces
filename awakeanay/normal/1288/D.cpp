#include <iostream>
#include <algorithm>
#include <vector>

struct num
{
	int x, i, j;	
};

inline bool operator<(num &a, num &b) {
	return a.x < b.x;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);
	
	int n, m;
	std::cin >> n >> m;
	
	std::vector<num> seq(n*m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int x;
			std::cin >> x;
			seq[m*i+j].x = -x;
			seq[m*i+j].i = i;
			seq[m*i+j].j = j;
		}
	}

	std::sort(seq.begin(), seq.end());
	
	std::vector<int> avail((1<<m), 0);
	std::vector<int> cur(n, 0);
	avail[0] = 1;
	
	for(int k = 0; k < n*m; k++) {
		int i = seq[k].i;
		int j = seq[k].j;
		
		cur[i] += (1<<j);
		avail[cur[i]] = i+1;
		
		if(avail[(1<<m)-cur[i]-1]) {
			std::cout << avail[(1<<m)-cur[i]-1] << " " << i+1 << std::endl;
			break;
		}
	}
	
	return 0;
}