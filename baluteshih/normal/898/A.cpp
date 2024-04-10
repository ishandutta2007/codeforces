#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	if(n-n/10*10>n/10*10+10-n) cout << n/10*10+10 << "\n";
	else cout << n/10*10 << "\n";
 }