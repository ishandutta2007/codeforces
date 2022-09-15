#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int p[202020];
int ansp[202020];

int disj[202020];
bool visit[202020];
int Find(int a)
{
	if (disj[a] == a) return a;
	else return disj[a] = Find(disj[a]); 
}

void Union(int a, int b)
{
	disj[Find(a)] = Find(b);
}


int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) disj[i] = i;
	bool self = false;
	int inode = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", p + i);
		p[i]--;
		ansp[i] = p[i];
		Union(i, p[i]);
		if (i == p[i])
		{
			self = true;
			inode = i;
		}
	}
	vector<int> a;
	for (int i = 0; i < N; i++) a.push_back(Find(i));
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	vector<int> b;
	b.push_back(Find(inode));
	for (int i = 0; i < a.size(); i++)
		if (b[0] != a[i]) b.push_back(a[i]);
	for (int i = 0; i < a.size(); i++) a[i] = b[i];
	int acnt = 0;
	for (int i = 1; i < a.size(); i++)
	{
		int run = a[i];
		while (!visit[run])
		{
			visit[run] = true;
			run = p[run];
		}
		ansp[run] = a[0];
		acnt++;
	}
	if (!self)
	{
		int run = a[0];
		while (!visit[run])
		{
			visit[run] = true;
			run = p[run];
		}
		ansp[run] = run;
		acnt++;
	}
	printf("%d\n", acnt);
	for (int i = 0; i < N; i++) printf("%d ", ansp[i]+1);
}