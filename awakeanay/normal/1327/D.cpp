#include <iostream>
#include <vector>

signed main() {
	int t;
	std::cin >> t;

	while(t--) {
		int n;
		std::cin >> n;

		int p[n];
		int c[n];

		for(int i = 0; i < n; i++) {
			std::cin >> p[i];
			p[i]--;
		}

		for(int i = 0; i < n; i++) 
			std::cin >> c[i];

		std::vector<int> vis(n, 0);
		int ans = n;
		for(int i = 0; i < n; i++) {
			if(!vis[i]) {
				std::vector<int> cur;
				cur.push_back(i);
				vis[i] = true;
				
				int x = i;
				while(p[x] != i) {
					x = p[x];
					cur.push_back(x);
					vis[x] = true;
				}

				int k = cur.size();
				for(int j = 1; j*j <= k; j++) {
					if(k % j)
						continue;

					for(int l : {j, k/j}) {
						std::vector<int> kind(l, -1);
						for(int m = 0; m < l; m++)
							kind[m] = c[p[cur[m]]];

						for(int m = l; m < k; m++) {
							if(kind[m%l] != c[p[cur[m]]])
								kind[m%l] = -1;
						}
								
						for(int m : kind)
							if(m > 0)
								ans = std::min(ans, l);
					}
				}
			}
		}

		std::cout << ans << std::endl;
	}

	return 0;
}