#include <iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	cout << 2LL*(c+min(a,b))+(max(a,b)!=min(a,b));
}