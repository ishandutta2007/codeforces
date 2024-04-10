#include <iostream>

#include <vector>

using namespace std;

vector<int> v;
int main()
{
	int n, g = 0, max1 = 0, max2 = 0;
	string s;
	cin >> n;
	cin >> s;
	int j = 0;
	while(s[j] == 'S')
	{
		j ++;
	}
	for(int i = j; i < s.size(); i ++)
	{
		if(s[i] == s[i - 1])
		{
			v[v.size() - 1] ++;
		}
		else
		{
			v.push_back(1);
		}
		if(s[i] == 'G')
		{
			g ++;
		}
	}
	for(int i = 0; i < v.size(); i += 2)
	{
		max1 = max(max1, v[i]);
	}
	for(int i = 2; i < v.size(); i += 2)
	{
		if(v[i - 1] == 1)
		{
			max2 = max(max2, v[i] + v[i - 2]);
		}
	}
	if(v.size() > 4)
	{
		cout << max(max1 + 1, max2 + 1);
	}
	if(v.size() > 2 && v.size() <= 4)
	{
		cout << max(max1 + 1, max2);
	}
	if(v.size() <= 2)
	{
		cout << g;
	}
}