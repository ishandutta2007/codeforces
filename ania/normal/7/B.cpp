#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>
using namespace std;

#define fore(i,n) for(int i = 0; i < (n); i++)
#define fort(i,n) for(typeof((n).begin()) i = (n).begin(); i != (n).end(); i++)

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;

#define err(...) fprintf(stderr, __VA_ARGS__);

char ex[111];
int m,cur;
int q[111];
int jump[111];
int pos[111];
int who[111];

void test()
{
	int n;
	scanf("%s", ex);
	if(ex[0] == 'a')
	{
		scanf("%d", &n);
		int fnd = -1;
		for(int i = 0; i < m; )
		{
			if(q[i] == 0)
			{
				bool wr = 0;
				fore(j,n) if(q[i+j])
				{
					wr = 1;
					break;
				}
				if(wr)
				{
					i++;
					continue;
				}
				fnd = i;
				break;
			}
			else
			{
				i += jump[i];
			}
		}
		if(fnd != -1)
		{
			printf("%d\n", ++cur);
			pos[cur] = fnd;
			who[fnd] = cur;
			jump[fnd] = n;
			fore(j,n) q[fnd+j] = 1;
		}
		else
		{
			printf("NULL\n");
		}
	}
	else if(ex[0] == 'e')
	{
		scanf("%d", &n);
		if(n >= 1 && n <= cur && pos[n] != -1)
		{
			int x = pos[n];
			int temp = jump[x];
			fore(i,temp) q[x+i] = 0;
			jump[x] = 0;
			who[x] = 0;
			pos[n] = -1;
		}
		else printf("ILLEGAL_ERASE_ARGUMENT\n");
	}
	else
	{
		for(int i = 0, j = 0; i < m; )
		{
			if(q[i])
			{
				int temp = jump[i];
				int ww = who[i];
				who[i] = 0;
				who[j] = ww;
				pos[ww] = j;
				jump[i] = 0;
				jump[j] = temp;
				fore(k,temp) q[i+k] = 0;
				fore(k,temp) q[j+k] = 1;
				i += temp;
				j += temp;
			}
			else i++;
		}
	}
	/*
	fore(i,m) printf("%d ", q[i]); printf("\n");
	fore(i,m) printf("%d ", who[i]); printf("\n");
	fore(i,m) printf("%d ", jump[i]); printf("\n");
	fore(i,m) printf("%d ", pos[i]); printf("\n");
	*/
}

int main()
{
	int t;
	scanf("%d%d", &t,&m);
	q[m] = 1;
	while(t--) test();
}