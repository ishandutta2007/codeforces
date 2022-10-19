#include <iostream>
using namespace std;

long long fact(long long n){
	if(n==0) return 1;
	return n * fact(n-1);
}

int main() {
	long long n, m;
	cin >> n >> m;
	if(m<n){
		n = m;
	}
	cout << fact(n) << endl;
	return 0;
}