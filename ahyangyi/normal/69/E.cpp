#include <stdio.h>
#include <map>
#include <set>

using namespace std;

int data[100000];
int n, m;
map<int, int> ct;
set<int> psb;

void output ()
{
	if (psb.size())
		printf ("%d\n", *psb.rbegin());
	else
		printf ("Nothing\n");
}

int main ()
{

	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i ++)
		scanf ("%d", data + i);

	for (int i = 0; i < m; i ++)
		ct[data[i]] ++;

	for (map<int,int>::iterator it = ct.begin(); it != ct.end(); it ++)
		if (it->second == 1)
			psb.insert(it->first);

	output();

	for (int i = m; i < n; i ++)
	{
		if (ct[data[i - m]] == 1)
			psb.erase(data[i - m]);
		ct[data[i - m]] --;
		if (ct[data[i - m]] == 1)
			psb.insert(data[i - m]);

		if (ct[data[i - 0]] == 1)
			psb.erase(data[i - 0]);
		ct[data[i - 0]] ++;
		if (ct[data[i - 0]] == 1)
			psb.insert(data[i - 0]);

		output ();
	}

	return 0;
}