#include <iostream>

using namespace std;

int s[500005];
int main()
{
	int a, b, c, d;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	int i = 0, j = 0;
	while(i * (i - 1) < a * 2)
	{
		i ++;
	}
	while(j * (j - 1) < d * 2)
	{
		j ++;
	}
	if(a == 0)
	{
		if(b + c == 0)
		{
			i = 0;
		}
		else
		{
			i = 1;
		}
	}
	if(d == 0)
	{
		if(b + c == 0)
		{
			j = 0;
		}
		else
		{
			j = 1;
		}
	}
	if(i * (i - 1) != a * 2 || j * (j - 1) != d * 2 || (i + j) * (i + j - 1) != (a + b + c + d) * 2)
	{
		cout << "Impossible";
	}
	else
	{
		if(a + d == 0)
		{
			if(b + c == 1)
			{
				i = 1;
				j = 1;
			}
			else
			{
				i = 1;
			}
		}
		//cout << i << " " << j << endl;
		int cnt = 0, s = 0;
		for(int k = 0; k < i + j; k ++)
		{
			//cout << s << " " << cnt << " " << endl;
			if(s + j - cnt <= b)
			{
				cout << 0;
				s += j - cnt;
			}
			else
			{
				cout << 1;
				cnt ++;
			}
		}
	}
	return 0;
}