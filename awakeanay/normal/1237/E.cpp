#include <iostream>
#include <vector>

#define LOG 40

#define int long long

signed main() {
	int n;
	std::cin >> n;

	std::vector<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(4);
	list.push_back(5);

	int a = 2, b = 1, x = 2;
	int A, B, X;
	for(int i = 3; i < LOG; i++) {
		X = b+x+1;
		A = b+x+1;
		B = a+x+1;

		list.push_back(A+X+1);
		list.push_back(B+X+1);
		a = A;
		b = B;
		x = X;
	}

	for(int i = 0; i < list.size(); i++)
	{
		if(list[i] == n) {
			std::cout << 1 << std::endl;
			return 0;
		}
	}

	std::cout << 0 << std::endl;
	return 0;
}