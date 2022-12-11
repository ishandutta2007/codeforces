#include <cstdio>
#include <algorithm>
#include <set>
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

#define mod 1000000007
#define maxn 100100

int sum;
vector<pi> wait;
pi t[maxn];
multiset<pi, greater<pi> > all;
int d[maxn];
int res;

void add(pi a)
{
	all.insert(a);
	sum += a.y;
	if(sum >= mod) sum -= mod;
}

void rmax(int a)
{
	while(all.size() && all.begin() -> x > a)
	{
		sum -= all.begin() -> y;
		if(sum < 0) sum += mod;
		all.erase(all.begin());
	}
	/*
	printf("usuawam %d: ", a);
	tr(i,all) printf("[%d %d] ", i->x, i->y);
	printf("\n");
	*/
}

int main()
{
	int n,m;
	scanf("%d%d", &m, &n);
	fore(i,n) scanf("%d%d", &t[i].y, &t[i].x);
	sort(t,t+n);
	if(t[n-1].x == m) d[n-1] = 1;
	wait.pb(mp(t[n-1].y, d[n-1]));
	for(int i = n-2; i >= 0; i--)
	{
		if(t[i].x != t[i+1].x)
		{
			tr(j,wait) add(*j);
			wait.clear();
		}
		rmax(t[i].x);
		d[i] = sum;
		if(t[i].x == m) d[i] = 1;
		wait.pb(mp(t[i].y, d[i]));
	}
	fore(i,n) if(t[i].y == 0)
	{
		res += d[i];
		if(res >= mod) res -= mod;
	}
	printf("%d\n", res);
}