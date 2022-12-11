#include <iostream>
using namespace std;

bool estConcat(long long t, long long nb) {
	if(t > nb)
		return false;
	if(t == nb)
		return true;
	
	bool res = false;
	
	res = res || estConcat(t * 10 + 1, nb);
	res = res || estConcat(t * 100 + 14, nb);
	res = res || estConcat(t * 1000 + 144, nb);
	
	return res;
}

int main() {
	long long nb;
	cin >> nb;
	
	if(estConcat(0, nb)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}