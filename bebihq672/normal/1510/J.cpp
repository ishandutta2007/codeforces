#include<bits/stdc++.h>
using namespace std;

char s[101010];

vector<int> a, b, ans;

bool fucked[101010];

int main()
{
	scanf("%s", s);
	
	int delta = 100000;
	
	int len = strlen(s);
	
	int last = 0;
	
	for(int i = 0; i <= len; i++)
	if(s[i] == '#' || i == len)
	{
		a.push_back(i - last);
		if(i < len)
			b.push_back(1);
		while(i + 1 < len && s[i + 1] == '#')
		{
			i++;
			b[b.size() - 1]++;
		}
		last = i + 1;
	}
	
	if(a.size() == 1)
	{
		puts("0");
		puts("");
		return 0;
	}
	
	for(int i = 0; i < (int)a.size(); i++)
	{
		if(i == 0 || i == a.size() - 1)
		{
			delta = min(delta, a[i]);
			fucked[a[i] - 1] = 1;
		}
		else
		{
			delta = min(delta, a[i] - 1);
			fucked[a[i] - 2] = 1;
		}
	}
	
	int tmp = 0;
	
	for(int i = delta; i >= 0; i--)
	if(!fucked[i])
	{
		tmp = i;
		break;
	}
	
	if(tmp == 0)
	{
		if(a[0] != 0)
		{
			puts("-1");
			return 0;
		}
		if(a[a.size() - 1] != 0)
		{
			puts("-1");
			return 0;
		}
		for(int i = 1; i < a.size() - 1; i++)
		if(a[i] != 1)
		{
			puts("-1");
			return 0;
		}
		printf("%d\n", (int)b.size());
		for(int x: b)
			printf("%d ", x);
		puts("");
		return 0;
	}
	
	for(int x: a)
		cerr << x << " ";
	cerr << endl;
	for(int x: b)
		cerr << x << " ";
	cerr << endl;
	cerr << tmp << endl;
	
	for(int i = 0; i < a.size(); i++)
	{
		a[i] -= tmp;
		if(i != 0 && i != a.size() - 1)
			a[i]--;
		while(a[i] > 0)
		{
			if(a[i] == 3)
			{
				if(tmp == 1)
				{
					puts("-1");
					return 0;
				}
				a[i] -= 3;
				ans.push_back(2);
			}
			else
			{
				ans.push_back(1);
				a[i] -= 2;
			}
		}
		if(i < b.size())
			ans.push_back(b[i] + tmp);
	}
	printf("%d\n", (int)ans.size());
	for(int x: ans)
		printf("%d ", x);
	puts("");
	
	return 0;
}