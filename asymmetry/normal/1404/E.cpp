#include <bits/stdc++.h>
#pragma GCC optimize "O3"

using namespace std;

int n, m, l, ll, odp;
int p[502][502][4]; // 0-gora; 1-prawo; 2-dol; 3-lewo;
int sko[2000000];
int odw[2000000];
char s[502][502];
vector <int> v[2000000];

bool skoj(int x)
{
	odw[x]=ll;
	for(int i:v[x])
	{
		if(!sko[i])
		{
			sko[x]=i;
			sko[i]=x;
			return true;
		}
	}
	for(int i:v[x])
	{
		if(odw[sko[i]]<ll)
		{
			if(skoj(sko[i]))
			{
				sko[x]=i;
				sko[i]=x;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i)
	{
		scanf("%s", s[i]+1);
		for(int j=1; j<=m; ++j)
		{
			odp+=s[i][j]=='#';
		}
	}
	for(int i=2; i<=n; ++i)
	{
		for(int j=1; j<=m; ++j)
		{
			if(s[i][j]=='#' && s[i-1][j]=='#')
			{
				++l;
				p[i][j][0]=l;
				p[i-1][j][2]=l;
			}
		}
	}
	for(int i=1; i<=n; ++i)
	{
		for(int j=2; j<=m; ++j)
		{
			if(s[i][j]=='#' && s[i][j-1]=='#')
			{
				++l;
				p[i][j][3]=l;
				p[i][j-1][1]=l;
			}
		}
	}
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=m; ++j)
		{
			if(s[i][j]=='#' && s[i-1][j]=='#' && s[i][j+1]=='#')
			{
				v[p[i][j][0]].push_back(p[i][j][1]);
				v[p[i][j][1]].push_back(p[i][j][0]);
			}
			if(s[i][j]=='#' && s[i-1][j]=='#' && s[i][j-1]=='#')
			{
				v[p[i][j][0]].push_back(p[i][j][3]);
				v[p[i][j][3]].push_back(p[i][j][0]);
			}
			if(s[i][j]=='#' && s[i+1][j]=='#' && s[i][j+1]=='#')
			{
				v[p[i][j][2]].push_back(p[i][j][1]);
				v[p[i][j][1]].push_back(p[i][j][2]);
			}
			if(s[i][j]=='#' && s[i+1][j]=='#' && s[i][j-1]=='#')
			{
				v[p[i][j][2]].push_back(p[i][j][3]);
				v[p[i][j][3]].push_back(p[i][j][2]);
			}
		}
	}
	for(int i=1; i<=l; ++i)
	{
		if(!sko[i])
		{
			++ll;
			odp+=skoj(i);
		}
	}
	printf("%d\n", odp-l);
	return 0;
}