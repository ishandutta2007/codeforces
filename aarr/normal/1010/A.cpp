#include <iostream>

#include <iomanip>

using namespace std;

int main()
{
	int n;
	double m, ans;
	cin >> n;
	cin >> m;
	ans = m;
	for(int i = 0; i < 2 * n; i ++)
	{
		double x;
		cin >> x;
		if(x == 1)
		{
			cout << -1;
			return 0;
		}
		ans *= x / (x - 1); 
	}
	ans -= m;
	cout << fixed << setprecision(10);
	cout << ans;
	return 0;
}