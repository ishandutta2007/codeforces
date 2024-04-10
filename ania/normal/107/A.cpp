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

#define maxn 1010

int inp[maxn], outp[maxn], inc[maxn], outc[maxn];

int main()
{
	int n,p,a,b,d;
	scanf("%d%d", &n, &p);
	fore(i,n) outp[i] = inp[i] = -1;
	fore(i,p)
	{
		scanf("%d%d%d", &a, &b, &d);
		a--; b--;
		outp[a] = b;
		inp[b] = a;
		outc[a] = d;
		inc[b] = d;
	}
	int res = 0;
	fore(i,n) if(outp[i] == -1 && inp[i] != -1) res++;
	printf("%d\n", res);
	fore(i,n) if(inp[i] == -1 && outp[i] != -1)
	{
		int x = i;
		d = outc[i];
		while(outp[x] != -1)
		{
			d = min(d, outc[x]);
			x = outp[x];
		}
		printf("%d %d %d\n", i+1, x+1, d);
	}
}