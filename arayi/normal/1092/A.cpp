#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;


int main()
{
	//freopen("convention2.in", "r", stdin);
	//freopen("convention2.out", "w", stdout);
	int t;
	cin >> t;
	string pat[101];
	for (int j = 0; j < t; j++)	
	{
		int n;
		cin >> n;
		int k;
		cin >> k;
		string a = "";
		for (int i = 0; i < n; i++)
		{
			a += ('a' + i % k);
		}
		pat[j] = a;
	}
	for (int i = 0; i < t; i++)
	{
		cout << pat[i] << endl;
	}
	return 0;
}