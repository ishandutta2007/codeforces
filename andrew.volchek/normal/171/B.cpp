#include <iostream>

using namespace std;
#define ull unsigned long long
int main()
{
	ull a;
	cin >> a;
	a--;
	ull b = 3*a+1;
	ull c = (2+b-1)*b/2;
	ull d = (2+a-1)*a/2;
	d*=3;
	cout << d+c;
	return 0;
}