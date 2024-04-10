#include <iostream>
#include <string>

using namespace std;
int main()
{
	//int pizza[200000],n;
	int n, w ,* days, add=0;
	cin >> n;
	cin >> w;
	days = new int[n];
	cin >> days[0];
	for (int i = 1; i < n; i++) {
		cin >> days[i];
		if (days[i] + days[i - 1] < w) {
			add += w - days[i] - days[i - 1];
			days[i] = w - days[i - 1];
		}
	}
	cout << add << '\n' << days[0];
	for (int i = 1; i < n; i++) {
		cout << ' ' << days[i];
	}
	cout << '\n';
	//delete[] pizza;
	return 0;
}