#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define err(...) fprintf(stderr, __VA_ARGS__)

typedef pair<int,int> pi;
typedef long long int64;
typedef vector<int> vi;

#define fore(i,n) for(int i = 0; i < (n); i++)
#define tr(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define y second
#define mp make_pair
#define pb push_back

char s[222][222];

int main()
{
	int n,m;
	int x=0,res=0,maxy=0;
	scanf("%d%d", &n, &m);
	fore(i,n) scanf("%s", s[i]);
	fore(i,m) s[n][i] = 'G';
	fore(i,n) fore(j,m) if(s[i][j] == 'W') maxy = i;
	fore(i,maxy+1)
	{
		if(i%2==0)
		{
			int last = 0;
			for(int j = 0; j < m; j++)
				if(s[i][j] == 'W' || s[i+1][j] == 'W')
					last = j;
			if(x < last)
			{
				res += last-x;
				x = last;
			}
		}
		else
		{
			int first = n;
			for(int j = m-1; j >=0; j--)
			{
				if(s[i][j] == 'W' || s[i+1][j] == 'W')
				{
					first = j;
				}
			}
			if(first < x)
			{
				res += x-first;
				x = first;
			}
		}
		if(i != maxy) res++;
	}
	printf("%d\n",res);
}