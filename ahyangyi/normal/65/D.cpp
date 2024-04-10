#include <cstdio>
#include <set>
#include <string>

using namespace std;

int c2i (char ch)
{
	return ch == '?'? -1 :
		ch == 'G'? 0 : 
		ch == 'H'? 1 : 
		ch == 'R'? 2 : 
		3;
}

string i2s (int i)
{
	return i == 0? "Gryffindor":
		i == 1? "Hufflepuff":
		i == 2? "Ravenclaw":
		"Slytherin";
}

char data[10001];
int n;
int ans[4];
set<pair<pair<int,int>,pair<int,int> > > S;

void dfs (int i, int a, int b, int c, int d)
{
	if (S.find(make_pair(make_pair(a,b),make_pair(c,d))) != S.end())
		return;

	S.insert(make_pair(make_pair(a,b),make_pair(c,d)));

	if (i == n)
	{
		int min = a;
		if (b < min) min = b;
		if (c < min) min = c;
		if (d < min) min = d;

		if (a == min) ans[0] = 1;
		if (b == min) ans[1] = 1;
		if (c == min) ans[2] = 1;
		if (d == min) ans[3] = 1;

		return;
	}

	if (c2i(data[i]) == -1)
	{
		int min = a;
		if (b < min) min = b;
		if (c < min) min = c;
		if (d < min) min = d;

		if (a == min) dfs (i + 1, a + 1, b, c, d);
		if (b == min) dfs (i + 1, a, b + 1, c, d);
		if (c == min) dfs (i + 1, a, b, c + 1, d);
		if (d == min) dfs (i + 1, a, b, c, d + 1);
	}
	else if (c2i(data[i]) == 0)
	{
		dfs (i + 1, a + 1, b, c, d);
	}
	else if (c2i(data[i]) == 1)
	{
		dfs (i + 1, a, b + 1, c, d);
	}
	else if (c2i(data[i]) == 2)
	{
		dfs (i + 1, a, b, c + 1, d);
	}
	else 
	{
		dfs (i + 1, a, b, c, d + 1);
	}
}

int main ()
{
	scanf("%d", &n);
	scanf("%s", data);

	for (int i = 0; i < 4; i ++) ans[i] = 0;

	dfs(0, 0, 0, 0, 0);

	for (int i = 0; i < 4; i ++) if (ans[i]) printf ("%s\n", i2s(i).c_str());;

	return 0;
}