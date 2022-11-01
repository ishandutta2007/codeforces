#include <iostream>

using namespace std;

int main()
{
	char c1, c2;
	cin >> c1;
	cin >> c2;
	int n;
	cin >> n;
	if((c1 == '^' && c2 == 'v') || (c1 == 'v' && c2 == '^') || (c1 == '>' && c2 == '<') || (c1 == '<' && c2 == '>') || c1 == c2)
	{
		cout << "undefined";
	}
	if((c1 == '^' && c2 == '>') || (c1 == '>' && c2 == 'v') || (c1 == 'v' && c2 == '<') || (c1 == '<' && c2 == '^'))
	{
		if(n % 4 == 1)
		{
			cout << "cw";
		}
		else
		{
			cout << "ccw";
		}
	}
	if((c1 == '^' && c2 == '<') || (c1 == '>' && c2 == '^') || (c1 == 'v' && c2 == '>') || (c1 == '<' && c2 == 'v'))
	{
		if(n % 4 == 3)
		{
			cout << "cw";
		}
		else
		{
			cout << "ccw";
		}
	}
	return 0;
}