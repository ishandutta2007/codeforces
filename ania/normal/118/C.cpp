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
#define x first
#define y second
#define mp make_pair
#define pb push_back

char s[12345];
int cnt[11];
int best[11];
int used[11], nused[11];
int t[11][12234];
int n,k;

int get(int x)
{
	int rem = max(0, k - cnt[x]);
	int res = 0;
	used[0] = cnt[x];
	nused[0] = 0;
	for(int d = 1; d < 10; d++)
	{
		used[d] = 0;
		nused[d] = 0;
		if(x-d >= 0)
		{
			int amt = min(cnt[x-d], rem);
			used[d] = amt;
			nused[d] = cnt[x-d] - amt;
			rem -= amt;
			res += amt * d;
		}
		if(x+d < 10)
		{
			int amt = min(cnt[x+d], rem);
			used[d] += amt;
			nused[d] += cnt[x+d] - amt;
			rem -= amt;
			res += amt * d;
		}
	}
	return res;
}


int printout(int x)
{
	int val = get(x);
	fore(i,n)
	{
		int cur = s[i] - '0';
		int d = abs(cur-x);
		if(cur < x)
		{
			if(nused[d] > 0)
			{
				t[x][i] = cur;
				nused[d]--;
			}
			else
			{
				t[x][i] = x;
				used[d]--;
			}
		}
		else
		{
			if(used[d] > 0)
			{
				t[x][i] = x;
				used[d]--;
			}
			else
			{
				t[x][i] = cur;
				nused[d]--;
			}
		}
	}
	return val;
}

bool cmp(int a, int b)
{
	fore(i,n) if(t[a][i] != t[b][i]) return t[a][i] < t[b][i];
	return 0;
}

int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	fore(i,n) cnt[s[i]-'0']++;
	int res = 0;
	fore(i,10)
	{
		best[i] = printout(i);
		if(best[i] < best[res] || (best[i] == best[res] && cmp(i,res))) res = i;
	}
	printf("%d\n", best[res]);
	fore(i,n) printf("%d", t[res][i]);
	printf("\n");
	return 0;
}