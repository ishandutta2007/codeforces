#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

int a[100005];
vector<int> vx;
vector<int> vy;
int main()
{
	int n, l, x, y, p = 0;
	cin >> n;
	cin >> l;
	cin >> x;
	cin >> y;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
		if(a[i] + x <= l)
		{
			vx.push_back(a[i] + x);
		}
		if(a[i] - x >= 0)
		{
			vx.push_back(a[i] - x);
		}
		if(a[i] + y <= l)
		{
			vy.push_back(a[i] + y);
		}
		if(a[i] - y >= 0)
		{
			vy.push_back(a[i] - y);
		}
	}
	a[n] = 1000 * 1000 * 1000 + 5;
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	int i = 0, j = 0, k = 0;
	bool c = false, bx = false, by = false;
	vx.push_back(1000 * 1000 * 1000 + 6);
	vy.push_back(1000 * 1000 * 1000 + 7);
	for(int i = 0; i < vy.size(); i ++)
	{
		//cout << vy[i] << " ";
	}
	while(i <= n && j < vx.size() && k < vy.size())
	{
		//cout << i << " " << j << " " << k << endl;
		bool b = true;
		if(a[i] < vx[j] && a[i] < vy[k])
		{
			i ++;
			b = false;
		}
		if(vx[j] < a[i] && vx[j] < vy[k] && b)
		{
			j ++;
			b = false;
		}
		if(vy[k] < a[i] && vy[k] < vx[j] && b)
		{
			k ++;
			b = false;
		}
		if(vx[j] == a[i] && vy[k] == a[i] && b == true)
		{
			//cout << 84 << " " << i << " " << j << " " << k << endl;
			//cout << 79 << " " << k << " " << vy[k] << endl;
			i ++;
			j ++;
			k ++;
			b = false;
			c = true;
			bx = true;
			by = true;
			break;
		}
		if(vx[j] == vy[k] && b)
		{
			c = true;
			b = false;
			p = vx[j];
			j ++;
			k ++;
		}
		if(a[i] == vx[j] && b)
		{
			bx = true;
			b = false;
			//cout << a[i] << endl;
			i ++;
			j ++;	
		}
		if(a[i] == vy[k] && b)
		{
			by = true;
			//cout << a[i] << endl;
			i ++;
			k ++;
		}
	}
	bool b = true;
	if(bx && by)
	{
		cout << 0;
	}
	if(bx && !by)
	{
		cout << 1 << endl;
		cout << vy[0];
	}
	if(!bx && by)
	{
		cout << 1 << endl;
		cout << vx[0];
	}
	if(!bx && !by)
	{
		if(c)
		{
			cout << 1 << endl;
			cout << p;
		}
		else
		{
			cout << 2 << endl;
			cout << vx[0] << " " << vy[0];
		}
	}
	return 0;
}