#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int main()
{
	int n, s;
	cin >> n >> s;
	if (s%n == 0)
	{
		cout << s / n;
	}
	else
	{
		cout << s / n + 1;
	}
    return 0;
}