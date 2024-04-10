#include <iostream>
using namespace std;
string s[120];
int main()
{
	int n,m,x=-1,y=-1,x2=-1,y2=-1;
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	cin >> s[i];
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<m;j++)
		{
			if (s[i][j]=='B')
			{
				if (x==-1)
				{
					x=i;
					y=j+1;
				}
				x2=i;
				y2=j+1;
			}
		}
	}
	cout << (x+x2)/2 << ' ' << (y+y2)/2;
}