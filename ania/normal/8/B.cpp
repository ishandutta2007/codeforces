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

#define M 200

int px[4] = {1,0,-1,0}, py[4] = {0,1,0,-1};
bool v[2*M][2*M];
int n;
char t[M];
int q[333];

void go(int p, int x, int y)
{
	int s = 0;
	fore(i,4) if(v[x+px[i]][y+py[i]]) s++;
	if(s > 1 || v[x][y])
	{
		printf("BUG\n");
		exit(0);
	}
	v[x][y] = 1;
	if(p == n) return;
	int d = q[t[p]];
	go(p+1,x+px[d],y+py[d]);
}

int main()
{
	q['R'] = 0;
	q['D'] = 1;
	q['L'] = 2;
	q['U'] = 3;
	scanf("%s",t);
	for(n=0;t[n];n++) ;
	go(0,M,M);
	printf("OK\n");
}