#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

#define l first
#define r second

typedef long long ll;

pair<ll, ll> land[212345];
pair<ll, int> a[212345];
int ans[212345];

int
main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		cin >> land[i].l >> land[i].r;
	}
	vector<pair<pair<ll, ll>, int> > q;
	for(int i = 0; i+1 < n; i++)
	{
		q.push_back(pair<pair<ll,ll>, int> (pair<ll,ll> (land[i+1].l - land[i].r, land[i+1].r - land[i].l), i));
//		printf("%d %d\n",int(land[i+1].l - land[i].r), int(land[i+1].r - land[i].l));
	}
	sort(q.begin(), q.end());

	for(int i = 0; i < m; a[i].r = i+1, i++)
		cin >> a[i].l;
	sort(a, a+m);

	int i = 0;
	priority_queue<pair<ll, int> > rdm;
	for(int j = 0; j < m; j++)
	{
		while(i < q.size() && q[i].l.l <= a[j].l )
		{
			rdm.push(pair<ll, int> (-1 * q[i].l.r, q[i].r));
			i++;
		}

		while(!rdm.empty() && -1 * rdm.top().l < a[j].l)
		{
		//	printf("%d\n",  -1 * rdm.top().l );
			rdm.pop();
		}

		if(!rdm.empty())
		{
	//		printf("%d %d\n", rdm.top().r, a[j].r);
			ans[rdm.top().r] = a[j].r;
			rdm.pop();
		}
	}

	bool pos = true;
	for(int i = 0; i+1 < n; i++)
		if(ans[i] == 0)
			pos = false;
	if(pos)
	{
		printf("Yes\n");
		for(int i = 0; i+1 < n; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}
	else
		printf("No\n");
	return 0;
}