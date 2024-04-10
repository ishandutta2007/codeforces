#include <iostream>

#include <algorithm>

using namespace std;

pair<int, int> e[100005];
int main()
{
	int n, d, a, b;
	cin >> n;
	cin >> d;
	cin >> a;
	cin >> b;
	for(int i = 0; i < n; i ++)
	{
		int x, y;
		cin >> x;
		cin >> y;
		e[i] = {x * a + y * b, i + 1};
	}
	sort(e, e + n);
	int i = 0;
	while(d - e[i].first >= 0 && i < n)
	{
		d -= e[i].first;
		i ++;
	}
	cout << i << endl;
	for(int j = 0; j < i; j ++)
	{
		cout << e[j].second << " ";
	}
	return 0;
}