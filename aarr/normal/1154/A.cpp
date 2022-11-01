#include <iostream>

#include <algorithm>

using namespace std;

int a[10];
int main()
{
	for(int i = 0; i < 4; i ++)
	{
		cin >> a[i];
	}
	sort(a, a + 4);
	cout << a[3] - a[0] << " " << a[3] - a[1] << " " << a[3] - a[2];
}