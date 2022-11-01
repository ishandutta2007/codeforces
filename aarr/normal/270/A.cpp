#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i ++)
	{
		int n;
		cin >> n;
		if(360 % (180 - n) == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}