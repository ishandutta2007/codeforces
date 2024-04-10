#include <iostream>

#define MAXN 200000

int bit[MAXN];

void add(int x) {
	x += 1;
	while(x < MAXN)
	{
		bit[x]++;
		x += (x&(-x));
	}
}

int sum(int x) {
	int ret = 0;
	x += 1;
	while(x > 0)
	{
		ret += bit[x];
		//std::cout << x << " " << bit[x] << " here " << std::endl;
		x -= (x&(-x));
	}
	return ret;
}

int main() {
	int n;
	std::cin >> n;

	for(int i = 0; i < MAXN; i++)
		bit[i] = 0;

	int ent[n], ext[n];
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		ent[x-1] = i;
	}

	for(int i = 0; i < n; i++) {
		std::cin >> ext[i];
	}

	int ans = 0;
	for(int i = n-1; i >= 0; i--)
	{
		int x = ext[i]; x--;

		if(sum(ent[x]) > 0) {
			ans++;

		}

		add(ent[x]);
	}

	std::cout << ans << std::endl;

	return 0;
}