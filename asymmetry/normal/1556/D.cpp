//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

#define N 11000

int n, k;
int wo[N];
int wa[N];
int t[N];
//~ int tab[N];

int aska(int a, int b)
{
	cout<<"and "<<a<<" "<<b<<endl;
	int x;
	cin>>x;
	return x;
	//~ return tab[a]&tab[b];
}

int asko(int a, int b)
{
	cout<<"or "<<a<<" "<<b<<endl;
	int x;
	cin>>x;
	return x;
	//~ return tab[a]|tab[b];
}

void pri(int x)
{
	cout<<"finish "<<x<<endl;
	exit(0);
}

int main()
{
	scanf("%d%d", &n, &k);
	//~ for(int i=1; i<=n; ++i) scanf("%d", &tab[i]);
	int war=0, wan=0, wor=(1<<30)-1;
	for(int i=2; i<=n; ++i)
	{
		wo[i]=asko(1, i);
		wa[i]=aska(1, i);
		wan=wan|wa[i];
		wor=wor&wo[i];
	}
	int a23=aska(2, 3);
	for(int i=0; i<=30; ++i)
	{
		int j=1<<i;
		if(wor&j)
		{
			if(wan&j)
			{
				war+=j;
			}
			else
			{
				if(!(a23&j))
				{
					war+=j;
				}
			}
		}
	}
	t[1]=war;
	for(int i=2; i<=n; ++i)
	{
		t[i]=t[1]^(wo[i]-wa[i]);
	}
	//~ for(int i=1; i<=n; ++i) printf("%d ", t[i]);
	//~ printf("\n");
	sort(t+1, t+1+n);
	pri(t[k]);
	return 0;
}