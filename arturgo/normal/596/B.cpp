#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int nbPos;
	cin >> nbPos;
	
	long long cur = 0;
	
	long long nb = 0;
	
	long long val;
	for(int i = 0;i < nbPos;i++)
	{
		cin >> val;
		nb += abs(val - cur);
		cur = val;
	}
	
	cout << nb << endl;
	return 0;
}