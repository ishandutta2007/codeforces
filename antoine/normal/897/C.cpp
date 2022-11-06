#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>

std::string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
std::string f1[] = {
	"What are you doing while sending \"",
	"\"? Are you busy? Will you send \"",
	"\"?"
};

int f0Len;
int f1Len;

std::vector<long long> a(56);

char query(int n, long long k) {
	while (n >= a.size()) {
		if (k < f1[0].length())
			return f1[0][k];
		--n;
		k -= f1[0].length();
	}

	if (k >= a[n])
		return '.';

	if (n == 0)
		return f0[k];
	
	long long offsets[] = {
		0,
		f1[0].length() + a[n - 1],
		f1[0].length() + a[n - 1] + f1[1].length() + a[n - 1]
	};

	if (k < f1[0].length())
		return f1[0][k];

	if (k >= offsets[1] && k < offsets[1] + f1[1].length())
		return f1[1][k - offsets[1]];
	if (k >= offsets[2])
		return f1[1][k - offsets[2]];

	if (k < offsets[1])
		return query(n - 1, k - f1[0].length());
	return query(n - 1, k - offsets[1] - f1[1].length());
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	f0Len = f0.length();
	f1Len = f1[0].length() + f1[1].length() + f1[2].length();

	a[0] = f0Len;
	for (int i = 1; i < a.size(); ++i) {
		a[i] = a[i - 1] * 2 + f1Len;
		//std::cout << i << ' ' << a[i] << std::endl;
	}
	//return 0;

	int q;
	std::cin >> q;
	for (int i = 0; i < q; ++i) {
		int n;
		long long k;
		std::cin >> n >> k;
		--k;
		//std::cout << "__";
		std::cout << query(n, k);
		//std::cout << "__";
	}
	return 0;
}