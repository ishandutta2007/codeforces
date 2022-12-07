//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

int n;
int t[1000];

void solve()
{
	int x;
	scanf("%d%d", &n, &x);
	for(int i=1; i<=n; ++i) scanf("%d", &t[i]);
	sort(t+1, t+1+n);
	reverse(t+1, t+1+n);
	int w=0;
	for(int i=1; i<=n; ++i)
	{
		w+=t[i];
		if(w==x)
		{
			if(i==n)
			{
				printf("NO\n");
				return;
			}
			swap(t[i], t[i+1]);
			break;
		}
	}
	printf("YES\n");
	for(int i=1; i<=n; ++i) printf("%d ", t[i]);
	printf("\n");
}

int main()
{
	//~ ios_base::sync_with_stdio(false);
	//~ cin.tie(NULL);
	int q=1;
	scanf("%d", &q);
	while(q--)
	{
		solve();
	}
	return 0;
}