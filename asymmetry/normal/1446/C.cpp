#include <bits/stdc++.h>

using namespace std;

int solve(vector <int> g)
{
	if(g.size()==1)
	{
		return 0;
	}
	//~ printf("WYK: ");
	vector <int> t[60];
	int a, b;
	for(int i:g)
	{
		b=0;
		a=i;
		while(a)
		{
			++b;
			a>>=1;
		}
		t[b].push_back(i);
		//~ printf("%d ", i);
	}
	//~ printf("\n");
	int lg=0, wg=0, ret=1e9, w=0;
	for(int i=0; i<60; ++i)
	{
		lg+=t[i].size()>0;
	}
	for(int i=0; i<60; ++i)
	{
		if(t[i].empty()) continue;
		wg+=t[i].size()>0;
		for(int &j:t[i])
		{
			j^=1<<(i-1);
		}
		ret=min(ret, (int)g.size()-(int)t[i].size()-lg+wg-(wg>1)+solve(t[i]));
		w+=t[i].size();
	}
	return ret;
}

int main()
{
	int n;
	scanf("%d", &n);
	vector <int> t;
	for(int i=1; i<=n; ++i)
	{
		int a;
		scanf("%d", &a);
		t.push_back(a);
	}
	printf("%d\n", solve(t));
	return 0;
}