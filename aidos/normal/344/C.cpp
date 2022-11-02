#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
int main() {
	long long a, b, c = 0;
	cin >> a >> b;
	while(b != 1){
		c+=(a/b);
		long long x = a%b;
		a = b;
		b=x;
	}
	c+=(a/b);
	cout << c;
	return 0;
}