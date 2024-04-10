#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

vector<int> mine, atk, def;

int tab[112][112][112][3];
bool been[112][112][112][3];

int pd(int i, int j, int k, int kill_all)
{
	if(i == mine.size() && kill_all == 0)
		return 0;
	if(i == mine.size() && kill_all == 1)
		return (j == atk.size() && k == def.size()) ? 0 : -0x3f3f3f3f;

	if(been[i][j][k][kill_all])
		return tab[i][j][k][kill_all];
	been[i][j][k][kill_all] = true;

	int retv = pd(i+1, j, k, kill_all);

	retv = max(retv, pd(i+1, j, k, 1) + mine[i]);

	if(j < atk.size() && mine[i] >= atk[j])
		retv = max(retv, pd(i+1, j+1, k, kill_all) + mine[i] - atk[j]);

	if(k < def.size() && mine[i] > def[k])
		retv = max(retv, pd(i+1, j, k+1, kill_all));
	return tab[i][j][k][kill_all] = retv;
}

int main(void)
{
	string s;
	int n, m, a;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		cin >> s >> a;
		if(s == "ATK")
			atk.push_back(a);
		else
			def.push_back(a);
	}
	for(int i = 0; i < m; i++)
	{
		cin >> a;
		mine.push_back(a);
	}

	sort(mine.begin(), mine.end());
	sort(atk.begin(), atk.end());
	sort(def.begin(), def.end());
	printf("%d\n", pd(0, 0, 0, 0));
}