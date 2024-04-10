#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
char mark[4] = { 'v','<','^','>' };
int main()
{
	char c1, c2;
	cin >> c1 >> c2;
	int start, ending;
	for (int i = 0; i < 4; i++)
	{
		if (c1 == mark[i]) start = i;
		if (c2 == mark[i]) ending = i;
	}
	int d = ending - start;
	if (d < 0) d += 4;
	int num;
	cin >> num;
	num %= 4;
	if (d == 1)
	{
		if (num == 1) cout << "cw";
		else if (num == 3) cout << "ccw";
		else cout << "undefined";
	}
	else if (d == 3)
	{
		if (num == 1) cout << "ccw";
		else if (num == 3) cout << "cw";
		else cout << "undefined";
	}
	else cout << "undefined";
}