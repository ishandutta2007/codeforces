#include <iostream>

#define MAXN 200005

int a[MAXN], b[MAXN];
int n, k;

bool comp() {
	for(int i = 0; i < n; i++) {
		if(a[i] > b[i])
			return false;
		if(a[i] < b[i])
			return true;
	}
	return true;
}

void add() {
	for(int i = k-1; i >= 0; i--) {
		if(b[i] == 9)
			b[i] = 0;
		else {
			b[i] = b[i]+1;
			break;
		}
	}
}

int main() {
	std::cin >> n >> k;
	for(int i = 0; i < n; i++) {
		char c;
		std::cin >> c;
		a[i] = c - '0';
	}

	for(int i = 0; i < k; i++)
		b[i] = a[i];

	for(int i = k; i < n; i++)
		b[i] = b[i-k];

	if(!comp()) {
		add();
		for(int i = k; i < n; i++)
			b[i] = b[i-k];
	}

	std::cout << n << std::endl;

	for(int i = 0; i < n; i++)
		std::cout << b[i];

	std::cout << std::endl;

	return 0;
}