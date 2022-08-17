#include <iostream>
#include <algorithm>
#include <vector>

#define int long long
#define INF 10000000

signed main() {
	int n;
	std::cin >> n;
	
	int min[n], max[n], matter[n];
	int matters = n;
	std::vector<int> mmin, mmax;
	for(int i = 0; i < n; i++) {
		min[i] = INF;
		max[i] = 0;
		matter[i] = 1;
		int q;
		std::cin >> q;
		for(int j = 0; j < q; j++) {
			int x;
			std::cin >> x;
			if(x > min[i])
				matter[i] = 0;
			min[i] = std::min(x, min[i]);
			max[i] = std::max(x, max[i]);
		}
		if(matter[i]) {
			mmin.push_back(min[i]);
			mmax.push_back(max[i]);
			matters--;
		}
	}
	
	std::sort(mmin.begin(), mmin.end());
	
	int ans = 0;
	for(int i = 0; i < mmax.size(); i++) {
		//std::cout << mmin[i] << std::endl;
		ans += std::lower_bound(mmin.begin(), mmin.end(), mmax[i]) - mmin.begin();
		//std::cout << mmax[i] << " " << std::lower_bound(mmin.begin(), mmin.end(), mmax[i]) - mmin.begin() << std::endl;
	}
	
	//matters = n - matters;
	//std::cout << matters << " " << ans << std::endl;
	std::cout << ans + matters*(n-matters)*2 + matters*matters << std::endl;
	
	return 0;
}