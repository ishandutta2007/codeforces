#include <iostream>

using namespace std;

int main()
{
	bool d = 0;
	char a, b, c;
	cin >> b;
	cin >> c;
	for(int i = 0; i < 10; i ++)
	{
		cin >> a;
		if(a == b || a == c)
		{
			d = 1;
		}
	}
	if(d)
		cout << "YES";
	else
		cout << "NO";
}