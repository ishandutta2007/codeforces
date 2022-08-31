#include <iostream>

signed main()
{
	int t;
	std::cin >> t;

	while(t--) {
		std::string s;
		std::cin >> s;
		int n = s.length();

		int last[3];
		last[0] = last[1] = last[2] = -10000000;

		int ans = 10000000;
		for(int i = 0; i < n; i++) {
			int x = s[i] - '1';
			last[x] = i;
			ans = std::min(ans, std::max(last[0], std::max(last[1], last[2])) - 
					        std::min(last[0], std::min(last[1], last[2])) + 1);

		}
        if(ans >= 1000000)
            ans = 0;
		std::cout << ans << std::endl;
	}
}