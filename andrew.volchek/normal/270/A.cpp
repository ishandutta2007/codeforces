#include <iostream>

using namespace std;


int main()
{
	int n;
	cin >> n;

	for(int i=0;i<n;i++)
	{
		int ang;
		cin >> ang;
		if(ang ==0 || ang == 180)
		{
			cout << "NO" << endl;
			continue;
		}
		else
		{
			if(!(360 % (180-ang)))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

	return 0;
}