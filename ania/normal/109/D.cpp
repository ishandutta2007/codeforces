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

#define maxn 100100

bool lucky(int a)
{
	while(a)
	{
		if(a%10 != 4 && a%10 != 7) return 0;
		a /= 10;
	}
	return 1;
}

int n,q;
int t[maxn], where[maxn];
pi a[maxn], res[maxn];

void sw(int a, int b)
{
	res[q++] = mp(a,b);
	swap(t[a], t[b]);
	where[t[a]] = a;
	where[t[b]] = b;
}

int main()
{
	bool ok = 0;
	scanf("%d", &n);
	fore(i,n) scanf("%d", &a[i].x);
	fore(i,n) if(lucky(a[i].x)) ok = 1;
	if(!ok)
	{
		fore(i,n-1) if(a[i].x > a[i+1].x)
		{
			printf("-1\n");
			return 0;
		}
		printf("0\n");
		return 0;
	}
	int pos;
	fore(i,n) if(lucky(a[i].x)) pos = i;
	fore(i,n) a[i].y = i;
	sort(a,a+n);
	fore(i,n) t[a[i].y] = i;
	fore(i,n) where[t[i]] = i;
	int val = t[pos];
	fore(i,n) if(i != t[i] && val != i)
	{
		if(i != pos) sw(i,pos);
		pos = where[i];
		sw(pos, i);
	}
	printf("%d\n", q);
	fore(i,q) printf("%d %d\n", res[i].x+1, res[i].y+1);
	return 0;
}