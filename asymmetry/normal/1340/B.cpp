#include <bits/stdc++.h>

using namespace std;

int n, m, ll, p;
int kp[2001][10];
int dp[2001][2001];
int pp[2001][2001];
char c[8];
vector <int> v[2], odp;
vector <char> l[10];
bitset <2001> bt;

int main()
{
	l[0]={'1', '1', '1', '0', '1', '1', '1'};
	l[1]={'0', '0', '1', '0', '0', '1', '0'};
	l[2]={'1', '0', '1', '1', '1', '0', '1'};
	l[3]={'1', '0', '1', '1', '0', '1', '1'};
	l[4]={'0', '1', '1', '1', '0', '1', '0'};
	l[5]={'1', '1', '0', '1', '0', '1', '1'};
	l[6]={'1', '1', '0', '1', '1', '1', '1'};
	l[7]={'1', '0', '1', '0', '0', '1', '0'};
	l[8]={'1', '1', '1', '1', '1', '1', '1'};
	l[9]={'1', '1', '1', '1', '0', '1', '1'};
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i)
	{
		scanf("%s", c);
		for(int j=0; j<8; ++j)
		{
			for(int k=0; k<10; ++k)
			{
				if(c[j]=='1')
				{
					if(l[k][j]=='0')
					{
						kp[i][k]=1e9;
					}
				}
				else
				{
					if(l[k][j]=='1')
					{
						++kp[i][k];
					}
				}
			}
		}
	}
	ll=0;
	p=1;
	v[0].push_back(0);
	for(int i=0; i<n; ++i)
	{
		bt^=bt;
		for(int j:v[ll])
		{
			for(int k=9; k>=0; --k)
			{
				if(j+kp[i+1][k]<=m)
				{
					if(!bt[j+kp[i+1][k]])
					{
						bt[j+kp[i+1][k]]=1;
						pp[i+1][j+kp[i+1][k]]=j;
						dp[i+1][j+kp[i+1][k]]=k;
						v[p].push_back(j+kp[i+1][k]);
					}
				}
			}
		}
		v[ll].clear();
		swap(ll, p);
	}
	if(!bt[m])
	{
		printf("-1\n");
		return 0;
	}
	for(int i=n; i; --i)
	{
		odp.push_back(dp[i][m]);
		m=pp[i][m];
	}
	while(!odp.empty())
	{
		printf("%d", odp.back());
		odp.pop_back();
	}
	return 0;
}