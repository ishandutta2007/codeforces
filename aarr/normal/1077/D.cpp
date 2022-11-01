#include <iostream>

#include <vector>

using namespace std;

int a[200005];
int b[200010];
int n, k;
vector<int> v;
bool isval(int md)
{
	int s = 0;
	if(md < 1)
	{
		return true;
	}
	for(int i = 1; i <= 200005; i ++)
	{
		s += b[i] / md;
	}
	if(s < k)
	{
		return false;
	}
	else
	{
		while(v.size())
		{
			v.pop_back();
		}
		for(int i = 1; i <= 200005; i ++)
		{
			for(int j = 0; j < b[i] / md; j ++)
			{
				if(v.size() < k)
				{
					v.push_back(i);
				}
			}
		}
		return true;
	}
}
int main()
{
	cin >> n;
	cin >> k;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
		b[a[i]] ++;
	}
	int dw = -1, up = 200005;
	while(up - dw > 1)
	{
		int md = (up + dw) / 2;
		if(isval(md) == true)
		{
			dw = md;
		}
		else
		{
			up = md;
		}
	}
	for(int i = 0; i < v.size(); i ++)
	{
		cout << v[i] << " ";
	}
	return 0;
}