#include <iostream>
using namespace std;

long long ith(long long n, long long pos) {
	if(pos > n)
		cout << "Acces dehors" << endl;
	
	if(n == 1) {
		return 1;
	}
	
	if(pos % 2 == 1) {
		return (pos + 1) / 2;
	}
	
	if(n % 2 == 0) {
		return ith(n / 2, pos / 2) + n / 2;
	}
	else {
		if(pos == 2)
			return ith(n / 2, n / 2) + (n + 1) / 2;
		else
			return ith(n / 2, pos / 2 - 1) + (n + 1) / 2;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	long long n;
	int q;
	cin >> n >> q;
	
	for(int i = 0;i < q;i++) {
		long long pos;
		cin >> pos;
		cout << ith(n, pos) << endl;
	}
	return 0;
}