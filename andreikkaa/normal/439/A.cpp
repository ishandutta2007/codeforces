#include <iostream>

using namespace std;

int main()
{
	int n, d, s = 0;
	cin >> n >> d;
	int t[n];
	for(int i = 0; i < n; i++)
    	{
        	cin >> t[i];
        	s += t[i];
    	}
    	s += 10 * (n - 1);
    	if(s > d)
    	{
        	cout << -1;
        	return 0;
    	}
  	cout << (n - 1) * 2 + (d - s) / 5;
}