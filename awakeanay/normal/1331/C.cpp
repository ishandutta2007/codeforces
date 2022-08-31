#include <iostream>

int main() {
	int n;
	std::cin >> n;
	
	int p[6] = {0, 5, 3, 2, 4, 1};
  int rev[6];
  for(int i = 0; i < 6; i++)
    rev[p[i]] = i;

	int ans = 0;
	
	for(int i = 0; i < 6; i++) {
		if(n & (1 << i)) {
      ans += (1 << (5-rev[5-i]));
    }
	}
	
	std::cout << ans << std::endl;
}