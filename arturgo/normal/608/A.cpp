#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, h;
	cin >> n >> h;
	
	for(int iP = 0;iP < n;iP++)
	{
		int a, b;
		cin >> a >> b;
		h = max(h, a + b);
	}
	
	cout << h << endl;
	return 0;
}