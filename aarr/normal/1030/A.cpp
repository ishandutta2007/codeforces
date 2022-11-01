#include <iostream>

using namespace std;

int main()
{
	int n, x;
	cin >> n;
	cin >> x;
	for(int i = 1; i < n; i ++)
	{
		int y;
		cin >> y;
		x = x | y;
	}
	if(x)
		cout << "HARD";
	else
		cout << "EASY";
}