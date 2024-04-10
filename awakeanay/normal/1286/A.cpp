#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;

	int p[n+2];
	int types[2];
	types[1] = (n+1)/2;
	types[0] = n-types[1];

	for(int i = 1; i <= n; i++) {
		std::cin >> p[i];
		if(p[i]%2)
			types[1]--;
		else if(p[i] > 0)
			types[0]--;
	}


	int final = n;
	n+=2;
	for(int m = 0; m < 4; m++)
	{
		p[0] = (m%2)+2;
		p[n-1] = (m<2)+2;

		int type[2] = {types[0], types[1]};

		std::vector<std::pair<int, int> > filler;
		int last = p[0];
		int gap = 0;
		int ans = 0;
		for(int i = 0; i < n; i++) {
			if(p[i] == 0)
				gap++;
			else {
				if(last%2 == p[i]%2)
					filler.push_back({gap, p[i]%2});
				else
					ans++;
				last = p[i];
				gap = 0;
			}
		}
		//filler.push_back({gap, last%2});

		std::sort(filler.begin(), filler.end());

		for(int i = 0; i < filler.size(); i++) {
			if(type[filler[i].second] < filler[i].first) {
				ans += 2*(filler.size()-i);
				break;
			}
			type[filler[i].second] -= filler[i].first;
		}

		final = std::min(final, ans);
	}

	std::cout << final << std::endl;

	return 0;
}