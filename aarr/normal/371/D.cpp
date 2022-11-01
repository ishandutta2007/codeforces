#include <iostream>

using namespace std;

int n, q;
int siz[200005];
int wat[200005];
int chld[200005];
int f(int v, int w)
{
	wat[v] += w;
	//cerr << 74 << " " << v << " " << w << " " << wat[v] << " " << siz[v] << endl;
	if(v == n)
	{
		wat[v] = min(siz[v], wat[v]);
		return v;
	}
	if(wat[v] < siz[v])
	{
		return v;
	}
	//cout << 63942379 << endl;
	if(v <= n)
	{
		chld[v] = f(chld[v], wat[v] - siz[v]);
		wat[v] = siz[v];
		return chld[v];
	}		
}
int main()
{
	ios :: sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> siz[i];
		chld[i] = i + 1;
	}
	cin >> q;
	for(int i = 0; i < q; i ++)
	{
		int x, y, z;
		cin >> x;
		if(x == 1)
		{
			cin >> y;
			cin >> z;
			f(y, z);
		}
		else
		{
			cin >> y;
			cout << wat[y] << endl;
		}
	}
	return 0;
}